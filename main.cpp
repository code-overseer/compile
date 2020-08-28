#include <cstdio>
#include "time.h"
#include "for.hpp"
#include "counter.hpp"
#include "intgen.hpp"
#include "strgen.hpp"
#include <array>

constexpr int f(); 
constexpr bool b1 = noexcept(f()); // false, undefined constexpr function
constexpr int f() { return 0; }
constexpr bool b2 = noexcept(f());

int main(int argc, char const* argv[])
{
    compile::for_<8>([](auto n){ printf("%s\n", compile::StrGen<n.value + 1>::value()); });
    compile::for_<8>([](auto n){ printf("%s\n", compile::StrGen<5>::value()); });

	return 0;
}
