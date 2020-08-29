#include <cstdio>
#include "time.h"
// #include "for.hpp"
// #include "counter.hpp"
// #include "intgen.hpp"
#include "time.hpp"
#include "strgen.hpp"
// #include "logic.hpp"
#include <utility>
#include "array.hpp"



template<typename T>
static void escape(T &&t) {
  __asm__ __volatile__ ("" : : "g" (t) : "memory");
}

static void clobber() {
  asm volatile("" : : : "memory");
}

void normal();

int main(int argc, char const* argv[])
{
    printf("%u\n", compile::TimeStamp::value);
    printf("%s\n", compile::StrGen<6>::value());
    printf("%s\n", compile::StrGen<6>::value());
    printf("%s\n", compile::StrGen<6>::value());
    printf("%s\n", compile::StrGen<6>::value());
	return 0;
}

