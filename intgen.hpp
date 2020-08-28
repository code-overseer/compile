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
        static constexpr uint32_t value = state;
        typedef IntGen<state> Next;
        struct Split 
        {
            typedef IntGen<state, A*A, 0, M> Gen1;
            typedef IntGen<Next::state, A*A, 0, M> Gen2;
        };
        static constexpr uint32_t x(int j = Counter::increment()) { return (state << (j % 32)) ^ (state ^ ~j); }
    };
}

#endif
