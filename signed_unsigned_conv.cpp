#include <iostream>

int main()
{
	// In general, it perfers converting to the larger scope of the two operands.
	int i = -42;
	unsigned u = 10;

	std::cout << i + i << std::endl; /* Outputs -84 */
	// unsigned int got a larger number representing scope than int
	std::cout << i + u << std::endl; /* Outputs 4294967264 */

	unsigned char uc = 10;
	// signed int got a larger scope than unsigned char
	std::cout << i + uc << std::endl;/* Outputs -32 */

	signed char sc = -42;
	// unsigned int got a larger scope than signed char
	std::cout << u + sc << std::endl;/* Outputs 4294967264 */

	return 0;
}

