#include <cstdio>
// #include "time.h"
#include "for.hpp"
// #include "counter.hpp"
// #include "intgen.hpp"
#include "strgen.hpp"
#include "logic.hpp"
#include <utility>
#include "array.hpp"


int main(int argc, char const* argv[])
{
    constexpr auto a = compile::Repeat<int, -1, 16>::value;
    compile::for_<16>([&](auto i){ printf("%i\n", a[i.value]); });
    compile::for_<16>([&](auto i){ printf("%s\n", compile::StrGen<5>::value()); });

	return 0;
}
