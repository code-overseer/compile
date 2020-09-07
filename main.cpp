#include <cstdio>
#include "counter.hpp"
#include "time.hpp"
#include "strgen.hpp"
#include "for.hpp"
#include <utility>
#include <type_traits>

int main(int argc, char const* argv[])
{
    printf("Random string\n");
    compile::for_<3>([&](auto i){ printf("%s\n", compile::StrGen<6>::value()); });
    compile::for_<3>([&](auto i){ printf("%s\n", compile::StrGen<18>::value()); });

    printf("\nEnsures compile time\n");
    constexpr char const* val{compile::StrGen<6>::value()};
    printf("%s\n", val);
    compile::for_<6>([&](auto i){ printf("%i ", std::integral_constant<char, val[i.value]>::value); });

    printf("\n\nCounter\n");
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>::increment()>::value);

	return 0;
}

