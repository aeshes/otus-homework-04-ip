#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <tuple>
#include <string>
#include <cstdint>

#include "traits.h"

template<typename T>
inline typename std::enable_if<std::is_integral<T>::value, void>::type
print_ip(T const&& ip) {
    std::cout << "integral" << std::endl;
}

template<typename T>
inline typename std::enable_if<std::is_same<T, std::string>::value, void>::type
print_ip(T const&& ip) {
    std::cout << "string" << std::endl;
}

template<typename T, typename = std::enable_if_t<is_vector_or_list_v<T>>>
void print_ip(T const&& c) {
    std::cout << "container" << std::endl;
}

template <typename... Args>
void print_tuple(std::tuple<Args...> const& tuple, std::ostream &out = std::cout) {
    std::cout << "tuple" << std::endl;
}

template <typename T, std::enable_if_t<is_tuple_v<T>, bool> = true>
void print_ip(T const &tuple, std::ostream &out = std::cout) {
    print_tuple(tuple, out);
}

int main()
{
    print_ip(int8_t{-1});
    print_ip(int16_t{0});
    print_ip(int32_t{2130706433});
    print_ip(int64_t{8875824491850138409});
    print_ip(std::string{"Hello, World!"});
    print_ip(std::vector<int>{100, 200, 300, 400});
    print_ip(std::list<short>{400, 300, 200, 100});
    print_ip(std::make_tuple(123, 456, 789, 0));

    return 0;
}
