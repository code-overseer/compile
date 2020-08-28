#include <cstdio>
#include "compile-time.h"
#include "compile-for.hpp"

int main(int argc, char const* argv[])
{
	printf("%lu\n", UNIX_TIMESTAMP);
	compile::for_<6>([](auto n){ printf("%lu\n", n.value); });
	
	return 0;
}