/*
 * Works with C++98:
 *	g++ pair_with_nonconstant_copy_only.cpp -o pair_with_nonconstant_copy_only -std=c++98
 * Error since C++11:
 *	g++ pair_with_nonconstant_copy_only.cpp -o pair_with_nonconstant_copy_only -std=c++11
 *
 * @https://stackoverflow.com/questions/16616266/why-was-the-stdpair-class-standard-changed-to-disallow-types-with-only-a-nonco
 */
#include <utility>

class A {
	public:
		A() {
		}
		// Uncomment the following const qualifer to make it pass.
		A(/* const */ A &) { // copy constructor with nonconstant reference
		}
};

int main()
{
	std::pair<A, int> p;
	//  error: use of deleted function 'constexpr std::pair<_T1, _T2>::pair(const std::pair<_T1, _T2>&) [with _T1 = A; _T2 = int]'
	std::pair<A, int> p1(p);
}
