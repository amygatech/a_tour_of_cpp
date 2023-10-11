
#include <iostream>
#include <string>
#include <optional>
#include <atomic>
#include <vector>
#include <fstream>
#include <filesystem>
#include <regex>

namespace view::thermal_interlock {

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
   
    std::cout << "print line: " << line << std::endl;
    return [line]() mutable -> std::string {
        if (!line.size()) return "";
        auto pos = line.find(',');
        if (pos == std::string_view::npos) {
            auto token = line;
            line = "";
            auto ret_str = std::string(trim_ws(token));
            std::cout << "===> ret-1: " << ret_str << std::endl;
            //return std::string(trim_ws(token));
            return (ret_str);
        }
        auto token = line.substr(0, pos);
        line = line.substr(pos + 1);
        auto ret  = std::string(trim_ws(token));
        //return std::string(trim_ws(token));
        std::cout << "===> ret: " << ret << std::endl;
        return (ret);
    };
}
inline auto load_data_lookup(std::filesystem::path file)
    -> std::vector<thermal_interlock_data_model> {
    auto ifs = std::ifstream(file);
    if (ifs.bad()) return {};
    std::string line;
    std::getline(ifs, line);
    std::vector<std::string> keys(3);

    std::generate(keys.begin(), keys.end(), split_line(line));
    std::vector<std::string>                  values(3);
    std::vector<thermal_interlock_data_model> thermal_data_vec;
    while (ifs.good()) {
        std::getline(ifs, line);
        std::generate(values.begin(), values.end(), split_line(line));
        thermal_interlock_data_model t_data;
        for (auto i = 0; i < keys.size(); ++i) {
            if (!values[i].size()) continue;
            if (keys[i] == "power")
                t_data.power = values[i];
            else if (keys[i] == "temperature")
                t_data.temperature = std::stoi(values[i]);
            else if (keys[i] == "voltage")
                t_data.voltage = std::stof(values[i]);
        }
        thermal_data_vec.push_back(std::move(t_data));
    }
    return thermal_data_vec;
}

} // namespace view::d2o



//My format 
//  Lat N 33 1 8.969
//  Lon W 117 5 39.541


int main() 
{  
    #if 0
    std::vector<::view::thermal_interlock::thermal_interlock_data_model>
        preamp_vector;

    preamp_vector = ::view::thermal_interlock::load_data_lookup(
        "data/preamp_interlock.csv");
    #endif

    //===============
    // test parsing
   
    std::string data_str = "Lat N 33 1 8.969 ";
    int degree;
    int min;
    float       sec;
    char        lat_lon[5];
    char        direction;

    sscanf(data_str.c_str(), "%s %c %d %d %f", lat_lon, 
                                        &direction, 
                                        &degree,&min, &sec);
    printf("\n============================\n");
    printf("%s \n", lat_lon);
    printf("%c \n", direction);
    printf("%d \n", degree);
    printf("%d \n", min);
    printf("%f \n", sec);

    
    #if 0
    //-------------
    //test string
    //-----------------
    std::string str_pos("Position");
    std::string str_pos_end("versasync");
    std::string gps_location{};

    std::string data_str = "gpsloc Position : Lat N 33 1 8.969 Lon W 117 5 39.541 Alt 233 m versasync: ~$ versasync :";
    std::size_t found = data_str.find(str_pos);
    std::size_t found_2 = data_str.find(str_pos_end);
    if (found != std::string::npos && 
        found_2 != std::string::npos) {
        size_t start = found + str_pos.size() + 2;
       gps_location = data_str.substr(start, found_2 - start );
       
    }
  
    std::cout << "===Result: \n";
    std::cout << gps_location << std::endl;
    #endif

   
	return 0;
}