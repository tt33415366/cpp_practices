#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using std::vector;

int main()
{
	vector<int> vec;
	std::istringstream iss("1 2 3 4 5 7 9 8");
	int i;

	while (iss >> i) {
		vec.push_back(i);
	}
	std::sort(vec.begin(), vec.end());
	for (auto e: vec) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::sort(vec.rbegin(), vec.rend());
	std::ostream_iterator<int> out_iter(std::cout, " ");
	std::copy(vec.begin(), vec.end(), out_iter);
	return 0;
}
