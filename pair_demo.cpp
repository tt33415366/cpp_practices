#include <iostream>
#include <utility>


template <typename T1, typename T2>
std::ostream& operator << (std::ostream & strm,
		const std::pair<T1, T2>& p)
{
//	return strm << "[" << p.first << ", " << p.second << "]";
	/* A tuple like interface */
	return strm << "[" << std::get<0>(p) << ", " << std::get<1>(p) << "]";
}
int main()
{
	std::pair<char, int> p('c', 101);

	std::cout << p << std::endl;

	return 0;
}
