#ifndef COMPILE_STRGEN_HPP
#define COMPILE_STRGEN_HPP

#include <cstdint>
#include "intgen.hpp"

namespace compile
{
    template<int... N>
    struct __StrGen {
        template <uint32_t I>
        using Rnd = IntGen<I>;

        template<int V>
        struct AlphaNum 
        {
            static constexpr char value()
            {
                auto constexpr mod = (Rnd<V>::value ^ sizeof...(N)) % 26;
                if constexpr (mod <= 9)
                {
                    return mod + '0';
                }
                if constexpr (Rnd<V>::Next::value % 2)
                {
                    return 'a' + mod;
                }
                return 'A' + mod;
            }
        };
    public:
        static constexpr char value[]{(AlphaNum<N>::value())...,'\0'};
    };

    template <std::size_t N, std::size_t ... Next>
    struct _StrGen : _StrGen<N-1U, N-1U, Next...>{ };

    template <std::size_t ... Next>
    struct _StrGen<0U, Next ... >{ using type = __StrGen<Next ... >; };

    template<int N>
    using StrGen = typename _StrGen<N>::type;
}

#endif
