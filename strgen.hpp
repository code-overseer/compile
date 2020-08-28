#ifndef COMPILE_STRGEN_HPP
#define COMPILE_STRGEN_HPP

#include <cstdint>
#include "intgen.hpp"
#include "counter.hpp"

namespace compile
{
    namespace
    {
        template<int... N>
        struct __StrGen 
        {
        private:
            template <uint32_t I>
            using Rnd = IntGen<I>;

            template<int V, int U = sizeof...(N)>
            struct AlphaNum 
            {
                static constexpr char value()
                {
                    auto constexpr mod = (Rnd<V>::value() ^ U) % 23 + (Rnd<V>::value() % 3);
                    auto constexpr branch = Rnd<V>::value() % 3;
                    if constexpr (!branch)
                    {
                        return mod % 7 + mod % 3 + '0';
                    }
                    if constexpr (branch == 1)
                    {
                        return 'a' + mod;
                    }
                    return 'A' + mod;
                }
            };

            template<int V>
            struct Array
            {
                static constexpr char value[]{(AlphaNum<N, V * sizeof...(N)>::value())...,'\0'};
            };
        public:
            template<int V = Counter<__StrGen<N...>>::increment()>
            static constexpr char const* value()
            {
                return Array<V>::value;
            }
        };

        template <std::size_t N, std::size_t ... Next>
        struct _StrGen : _StrGen<N-1U, N-1U, Next...>{ };

        template <std::size_t ... Next>
        struct _StrGen<0U, Next ... >{ using type = __StrGen<Next ... >; };
    }
    
    template<int N>
    using StrGen = typename _StrGen<N>::type;
}

#endif
