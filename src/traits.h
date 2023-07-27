#pragma once

#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

template<typename T>
struct is_vector_or_list : std::false_type {};

template<typename T>
struct is_vector_or_list<std::vector<T>> : std::true_type {};

template<typename T>
struct is_vector_or_list<std::list<T>> : std::true_type {};

template<typename T>
inline constexpr bool is_vector_or_list_v = is_vector_or_list<T>::value;

template <typename T>
struct is_tuple : std::false_type {};

template <typename... U>
struct is_tuple<std::tuple<U...>> : std::true_type {};

template<typename T>
inline constexpr bool is_tuple_v = is_tuple<T>::value;
