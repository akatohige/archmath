#include <iostream>
#include <arch/math.h>

using namespace scholar;

int main()
{
	auto matrix = float3x3::identity();
	std::cout << matrix << std::endl;
	return 0;
}