#include <cstdio>
#include "include/compile.hpp"
#include <utility>
#include <type_traits>

template<typename T, T Val>
using Number = std::integral_constant<T, Val>;

int main(int argc, char const* argv[])
{

    printf("Random string");
    compile::for_<3>([&](auto i){ printf("\n%s", compile::StrGen<6>{}.value()); });
    compile::for_<3>([&](auto i){ printf("\n%s", compile::StrGen<18>{}.value()); });

    printf("\n\nEnsures compile time\n");
    printf("%i\n", Number<char, compile::StrGen<6>{}.value()[compile::IntGen<0>{}.value() % 6]>::value);
#ifndef _MSC_VER
    /* MSVC doesn't like constexpr char const* */
    constexpr char const* val{compile::StrGen<6>{}.value()};
    printf("%s\n", val);
    compile::for_<6>([&](auto i){ printf("%i ", Number<char, val[i.value]>::value); });
#endif

    printf("\n\nCompile-time Repeat\n");
    constexpr std::size_t N = 5;
    using ULL = unsigned long long;
    using Array = compile::Repeat<ULL, 0xfa7e6b4c, N>;
    compile::for_<N>([&](auto i){ printf("%llu ", Number<ULL, Array::value[i.value]>::value); });

    printf("\n\nCounter");
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);

    printf("\n\nFunny stuff");
    for (auto i = 0; i < 4; ++i)
    {
        printf("\n%i", Number<int, compile::Counter<void>{}.increment()>::value);
    }

    printf("\n");
	return 0;
}

