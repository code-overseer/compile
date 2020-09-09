#include <cstdio>
#include "include/compile.hpp"
#include <utility>
#include <type_traits>

int main(int argc, char const* argv[])
{
    printf("Random string");
    compile::for_<3>([&](auto i){ printf("\n%s", compile::StrGen<6>{}.value()); });
    compile::for_<3>([&](auto i){ printf("\n%s", compile::StrGen<18>{}.value()); });

    printf("\n\nEnsures compile time\n");
    printf("%i\n", std::integral_constant<char, compile::StrGen<6>{}.value()[compile::IntGen<0>{}.value() % 6]>::value);
#ifndef _MSC_VER
    /* MSVC doesn't think the char const* is constexpr */
    constexpr char const* val{compile::StrGen<6>{}.value()};
    printf("%s\n", val);
    compile::for_<6>([&](auto i){ printf("%i ", std::integral_constant<char, val[i.value]>::value); });
#endif

    printf("\n\nCounter\n");
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);
    printf("%i\n", std::integral_constant<int, compile::Counter<void>{}.increment()>::value);

	return 0;
}

