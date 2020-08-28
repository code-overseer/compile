#include <cstdio>
#include "time.h"
#include "for.hpp"
#include "counter.hpp"
#include "intgen.hpp"
#include "strgen.hpp"

int main(int argc, char const* argv[])
{
	printf("%lu\n", UNIX_TIMESTAMP);
	compile::for_<6>([](auto n){ printf("%i\n", compile::IntGen<n.value>::value); });

    compile::for_<6>([](auto n){ printf("%s\n", compile::StrGen<n.value + 1>::value); });
    
	return 0;
}