#ifndef COMPILE_LOGIC_HPP
#define COMPILE_LOGIC_HPP

#include <type_traits>

namespace compile::Logic
{
    template <bool... b> struct AnyTrue;

    template <> struct AnyTrue<> : std::false_type {};

    template <bool... tail>
    struct AnyTrue<true, tail...> : std::true_type {};

    template <bool... tail>
    struct AnyTrue<false, tail...> : AnyTrue<tail...> {};

    template <bool... b> struct AllTrue;

    template <> struct AllTrue<> : std::true_type {};

    template <bool... tail>
    struct AllTrue<true, tail...> : AllTrue<tail...> {};

    template <bool... tail>
    struct AllTrue<false, tail...> : std::false_type {};
}

#endif
