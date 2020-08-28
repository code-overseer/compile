#include <cstdio>
#include "time.h"
#include "for.hpp"
#include "counter.hpp"
#include "intgen.hpp"
#include "strgen.hpp"

constexpr int f(); 
constexpr bool b1 = noexcept(f()); // false, undefined constexpr function
constexpr int f() { return 0; }
constexpr bool b2 = noexcept(f());

int main(int argc, char const* argv[])
{
	// compile::for_<6>([](auto n){ printf("%i\n", compile::IntGen<n.value>::value); });

    compile::for_<6>([](auto n){ printf("%s\n", compile::StrGen<n.value + 1>::value); });

    printf("%i\n", compile::Counter::increment());
    printf("%i\n", compile::Counter::increment());

	return 0;
}
