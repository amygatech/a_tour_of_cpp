#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>


/**
* Basic example with one variant
 */

struct Fluid {};
struct LightItem {};
struct HeavyItem {};
struct FragileItem {};

// Use example
// https://en.cppreference.com/w/cpp/utility/variant/visit
using var_t = std::variant<int, long, double, std::string>;
// helper constant for the visitor #3
template <class> inline constexpr bool always_false_v = false;

// helper type for the visitor #4
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

// explicit deduction guide (not needed as of C++20)
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;


using namespace std;

struct VisitPackage {
    void operator()(Fluid &) { cout << "fluid\n"; }
    void operator()(LightItem &) { cout << "light item\n"; }
    void operator()(HeavyItem &) { cout << "heavy item\n"; }
    void operator()(FragileItem &) { cout << "fragile\n"; }
};

int main() {
    // type-safe union
    std::variant<Fluid, LightItem, HeavyItem, FragileItem> package{
        FragileItem()};
    std::visit(VisitPackage(), package); //output fragile

    std::variant<int, std::string> var;
    var = "hello";
    // Prints "hello\n":
    std::visit([](auto &&info) { 
        std::cout << info << '\n'; 
        }, var);


    //-----------Use overload pattern-----------------
    // when error type traits not found, Press F5 to comtinue
    std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
    for (auto &v : vec) {
        // 1. void visitor, only called for side-effects (here, for I/O)
        std::visit([](auto &&arg) { std::cout << "\r\n arg: " << arg; }, v);

        // 2. value-returning visitor, demonstrates the idiom of returning
        // another variant
        var_t w = std::visit([](auto &&arg) -> var_t { return (arg + arg); }, v);

        // 3. type-matching visitor: a lambda that handles each type differently
        std::cout << " \r\n---------After doubling, variant holds -------------\r\n ";
        std::visit([](auto &&arg) {
             using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, int>)
                    std::cout << "int with value " << arg << '\n';
                else if constexpr (std::is_same_v<T, long>)
                    std::cout << "long with value " << arg << '\n';
                else if constexpr (std::is_same_v<T, double>)
                    std::cout << "double with value " << arg << '\n';
                else if constexpr (std::is_same_v<T, std::string>)
                    std::cout << "std::string with value " << std::quoted(arg)
                              << '\n';
                else
                    static_assert(always_false_v<T>, "non-exhaustive visitor!");

            }, w);

    }//end, for vec

    //--------------------------
    // use overload
    std::cout << " \r\n ##### Another type matchin vectore overloaded ########## \r\n";
    for (auto &v : vec) {
        // 4. another type-matching visitor: a class with 3 overloaded
        // operator()'s
        std::visit(
            overloaded{
                [](auto arg) { std::cout << arg << ' '; },
                [](double arg) { std::cout << std::fixed << arg << ' '; },
                [](const std::string &arg) {
                    std::cout << std::quoted(arg) << ' ';
                },
            }, v);
    }//end, for

    //====================================
    // Example of two packages
    std::variant<LightItem, HeavyItem> basicPackA;
    std::variant<LightItem, HeavyItem> basicPackB;

    std::cout << "\r\n ----Example of 2 packages : ---\r\n";

    std::visit(
        overloaded{
            [](LightItem &, LightItem &) { cout << "2 light items\n"; },
            [](LightItem &, HeavyItem &) { cout << "light & heavy items\n"; },
            [](HeavyItem &, LightItem &) { cout << "heavy & light items\n"; },
            [](HeavyItem &, HeavyItem &) { cout << "2 heavy items\n"; },
        },
        basicPackA, basicPackB); // will print "2 light items"


    return 0;
}