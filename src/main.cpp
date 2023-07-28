#include <iostream>
#include <string>
#include <tuple>

#include "traits.h"


template<typename T, enable_if_integral<T> = 0>
void print_ip(T const&& ip, std::ostream &out = std::cout) {
    const size_t size = sizeof(T);
    for (size_t i = size; i--;) {
        out << (ip >> (i << 3) & 0xFF);
        if (i > 0)
            out << '.';
    }
    out << std::endl;
}

template<typename T, enable_if_string<T> = 0>
void print_ip(T const&& ip, std::ostream &out = std::cout) {
    out << ip << std::endl;
}

template<typename T, enable_if_vector_or_list<T> = 0>
void print_ip(T const&& c, std::ostream &out = std::cout) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        out << *it;
        if (it != std::prev(c.end()))
            out << '.';
    }
    out << std::endl;
}

template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>, std::ostream &out = std::cout)
{
    (..., (out << (I == 0 ? "" : ".") << std::get<I>(_tup)));
}

template<class... T>
void print_tuple(const std::tuple<T...>& tuple, std::ostream &out = std::cout)
{
    print(tuple, std::make_index_sequence<sizeof...(T)>());
}

template<typename Tuple, size_t... I>
void print_tuple(Tuple const& t, std::index_sequence<I...>, std::ostream &out = std::cout) {
    size_t index = 0;
    auto printElem = [&index, &out](const auto& x) {
        if (index++ > 0)
            out << '.';
        out << x;
    };

    (printElem(std::get<I>(t)), ...);
}


template <typename Tuple, size_t Size = std::tuple_size_v<Tuple>, enable_if_tuple<Tuple> = 0>
void print_ip(Tuple const& tuple, std::ostream &out = std::cout) {
    print_tuple(tuple, std::make_index_sequence<Size>{});
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
