#include <iostream>
#include <bitset>

// As a terminate condition
void print() {}
template <typename T, typename ... Types>
void print(const T& firstArg, const Types& ... args)
{
	std::cout << firstArg << std::endl;
	print(args ...);
}

int main()
{
	print(7.5, "hello", std::bitset<16>(377), 42);
}
