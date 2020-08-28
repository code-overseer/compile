#ifndef COMPILE_INTGEN_HPP
#define COMPILE_INTGEN_HPP

#include <cstdint>
#include "time.h"
#include "counter.hpp"

namespace compile
{
    template<uint32_t S , uint32_t A = 16807UL, uint32_t C = 7UL, uint32_t M = (1UL<<31)-1>
    struct IntGen 
    {
        static constexpr uint32_t state = ((uint64_t)(S ? S : A) * A ^ UNIX_TIMESTAMP + C) % M;
        template <int N = Counter<IntGen<S>>::increment()>
        static constexpr uint32_t value() 
        { 
            return (state << (N % 31)) ^ (state ^ ~N); 
        }

        typedef IntGen<state> Next;
        struct Split 
        {
            typedef IntGen<state, A*A, 0, M> Gen1;
            typedef IntGen<Next::state, A*A, 0, M> Gen2;
        };
    };
}

#endif
