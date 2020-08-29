#ifndef COMPILE_STRGEN_HPP
#define COMPILE_STRGEN_HPP

#include <cstdint>
#include <utility>
#include "intgen.hpp"
#include "counter.hpp"

namespace compile
{
    namespace
    {
        template <typename U>
        struct _StrGen;

        template<int... N>
        struct _StrGen<std::integer_sequence<int, N...>>
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
            template<int V = Counter<_StrGen<std::integer_sequence<int, N...>>>::increment()>
            static constexpr char const* value()
            {
                return Array<V>::value;
            }
        };
    }
    
    template<int N>
    struct StrGen : _StrGen<std::make_integer_sequence<int, N>> {};
}

#endif
