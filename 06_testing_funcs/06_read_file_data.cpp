
#include <iostream>
#include <string>
#include <optional>
#include <atomic>
#include <vector>
#include <fstream>
#include <filesystem>


namespace view::d2o {
struct d2o_data_model {
    std::string power;
    int         temperature;
};

struct thermal_interlock_data_model {
    std::string power;
    int         temperature;
    float       voltage;
};

inline auto trim_ws(std::string_view key) -> std::string_view {
    constexpr auto space = " \f\n\r\t\v";
    auto           pos_start = key.find_first_not_of(space);
    if (pos_start == std::string_view::npos) return {};
    auto pos_end = key.find_last_not_of(space);
    if (pos_end == std::string_view::npos) return key.substr(pos_start);
    return key.substr(pos_start, pos_end - pos_start + 1);
}

inline auto split_line(std::string_view line) {
    return [line]() mutable -> std::string {
        if (!line.size()) return "";
        auto pos = line.find(',');
        if (pos == std::string_view::npos) {
            auto token = line;
            line = "";
            return std::string(trim_ws(token));
        }
        auto token = line.substr(0, pos);
        line = line.substr(pos + 1);
        return std::string(trim_ws(token));
    };
}
inline auto load_data_lookup(std::filesystem::path file)
    -> std::vector<d2o_data_model> {
    auto ifs = std::ifstream(file);
    if (ifs.bad()) return {};
    std::string line;
    std::getline(ifs, line);
    std::vector<std::string> keys(2);
    std::generate(keys.begin(), keys.end(), split_line(line));
    std::vector<std::string>    values(2);
    std::vector<d2o_data_model> d2o_vec;
    while (ifs.good()) {
        std::getline(ifs, line);
        std::generate(values.begin(), values.end(), split_line(line));
        d2o_data_model d2o_data;
        for (auto i = 0; i < keys.size(); ++i) {
            if (!values[i].size()) continue;
            if (keys[i] == "power")
                d2o_data.power = values[i];
            else if (keys[i] == "temperature")
                d2o_data.temperature = std::stoi(values[i]);
        }
        d2o_vec.push_back(std::move(d2o_data));
    }
    return d2o_vec;
}


} // namespace view::d2o


int main() {
    std::vector<::view::d2o::d2o_data_model> d2o_vector;

    d2o_vector = ::view::d2o::load_data_lookup("data/d2o_map.csv");

    double  amp1_current = 27.0025;
    double  amp2_current = 27.0025;
    int16_t amp1_setpoint = 29;
    

    //double min = (double)set_point - 2.00;
   // double max = (double)set_point + 2.00;

     if ((amp1_current < amp1_setpoint - 2) ||
        (amp1_current > amp1_setpoint + 2) ||
        (amp2_current < amp1_setpoint - 2) ||
        (amp2_current > amp1_setpoint + 2)) 
    {
         std::cout << " INTERLOCK HAPPEN ";
    }
    else 
    {
        std::cout << " IT'S NORMAL ";
    }
   
	return 0;
}