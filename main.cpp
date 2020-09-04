#include <cstdio>
#include "counter.hpp"
#include "time.hpp"
#include "strgen.hpp"
#include "for.hpp"
#include <utility>
#include <type_traits>


template<typename T>
static void escape(T &&t) {
  __asm__ __volatile__ ("" : : "g" (t) : "memory");
}

static void clobber() {
  asm volatile("" : : : "memory");
}

int main(int argc, char const* argv[])
{
    printf("Random string\n");
    compile::for_<6>([&](auto i){ printf("%s\n", compile::StrGen<6>::value()); });

    printf("\nCounter\n");

    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);

	return 0;
}

