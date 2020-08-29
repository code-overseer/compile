#ifndef COMPILE_MATH_HPP
#define COMPILE_MATH_HPP

namespace compile
{
    template<typename T, typename=typename std::enable_if<std::is_arithmetic<T>::value>::type>
    constexpr T pow(T base, std::size_t exp) { return base * (exp <= 1 ? 1 : pow(base, exp - 1)); }
}
#endif
