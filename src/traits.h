#pragma once

#include <type_traits>
#include <vector>
#include <list>
#include <tuple>
#include <string>

template<typename T> struct is_vector_or_list : std::false_type {};

template<typename T> struct is_vector_or_list<std::vector<T>> : std::true_type {};

template<typename T> struct is_vector_or_list<std::list<T>> : std::true_type {};

template<typename T> inline constexpr bool is_vector_or_list_v = is_vector_or_list<T>::value;

template<typename T> struct is_tuple : std::false_type {};

template<typename... U> struct is_tuple<std::tuple<U...>> : std::true_type {};

template<typename T> inline constexpr bool is_tuple_v = is_tuple<T>::value;

template<typename T>
using enable_if_string = std::enable_if_t<std::is_same_v<T, std::string>, int>;

template<typename T>
using enable_if_vector_or_list = std::enable_if_t<is_vector_or_list_v<T>, int>;

template<typename T>
using enable_if_tuple = std::enable_if_t<is_tuple_v<T>, int>;

template<typename T>
using enable_if_integral = std::enable_if_t<std::is_integral_v<T>, int>;

