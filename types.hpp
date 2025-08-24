#pragma once

#include "func.hpp"

using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using fld = long double;

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2d = vec<vec<T>>;
template <typename T>
using vec3d = vec<vec2d<T>>;
using veci = vec<int>;
using vec2i = vec2d<int>;
using vec3i = vec3d<int>;

using str = std::string;
using strv = std::string_view;

template <typename T>
using gp_queue = std::priority_queue<T>;
template <typename T>
using lp_queue = std::priority_queue<T, vec<T>, std::greater<>>;

template <typename T>
struct to_unsigned : std::make_unsigned<T> {};
template <>
struct to_unsigned<i128> {
  using type = u128;
};
template <typename T>
using to_unsigned_t = to_unsigned<T>::type;

template <typename T>
concept signed_integer = std::signed_integral<T> || std::is_same_v<T, i128>;
template <typename T>
concept unsigned_integer = std::unsigned_integral<T> || std::is_same_v<T, u128>;
template <typename T>
concept integer = signed_integer<T> || unsigned_integer<T>;
template <typename T>
concept vec_like = R::random_access_range<T> && R::sized_range<T>;
template <typename T>
concept vec2d_like = vec_like<T> && vec_like<R::range_value_t<T>>;