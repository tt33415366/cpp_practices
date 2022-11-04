#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	int n = 5;
	std::vector<int> vec = {3, 2, 1, 4, 5, 8, 9, 7, 1, 2};

	std::cout << "Original: " << std::endl;
	for (auto i: vec) {
		std::cout << i << ", ";
	}
	std::partial_sort(vec.begin(), vec.begin() + n, vec.end());
	std::cout << "\nAfter partial_sort(first, middle = [begin + 5], end):" << std::endl;
	for (auto i: vec) {
		std::cout << i << ", ";
	}
	std::partial_sort(vec.begin(), vec.begin() + n, vec.end(), [](int a, int b) { return a > b; });
	std::cout << "\nAfter partial_sort(first, middle = [begin + 5], end):" << std::endl;
	for (auto i: vec) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
	return 0;
}
