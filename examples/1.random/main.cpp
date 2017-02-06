#include <iostream>
#include <scholar.h>

using namespace scholar;

int main()
{
	std::cout << random() << std::endl;
	std::cout << random(-1.0, 1.0) << std::endl;
	std::cout << random(1, 3) << std::endl;
	return 0;
}