#include <functional>
#include <vector>
#include <list>
#include <iostream>

template <typename container>
void seq_container_filt(container &cont, bool (*p)(int))
{
	for (auto it = cont.cbegin(); it != cont.cend(); ) {
		if (p(*it)) {
			it = cont.erase(it);
		} else {
			++it;
		}
	}

	for (auto i : cont) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}
void vec_filt(std::vector<int> &cont, bool (*p)(int))
{
	for (auto it = cont.cbegin(); it != cont.cend(); ) {
		if (p(*it)) {
			it = cont.erase(it);
		} else {
			++it;
		}
	}

	for (auto i : cont) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

bool is_even(int i)
{
	return i % 2 == 0;
}

bool is_odd(int i)
{
	return i % 2 != 0;
}

int main()
{
	using std::vector;
	using std::list;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vi(ia, ia + (sizeof(ia) / sizeof(*ia)));
	list<int> li(ia, ia + ((sizeof(ia) / sizeof(*ia))));

	for (auto i : ia) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;

	vi.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	li.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	using namespace std::placeholders;

	/* seq_container_filt is a template, it is <unresolved overloaded function type> */
	// auto seq_even_filt = std::bind(seq_container_filt, _2, is_even);
	auto vec_even_filt = std::bind(vec_filt, _1, is_even);
	vec_even_filt(vi);
	seq_container_filt<vector<int>>(vi, is_even); 
	seq_container_filt<list<int>>(li, is_odd);
	std::cout << "----------------------------------" << std::endl;

	/* Template argument deduction */
	seq_container_filt(vi, is_even); 
	seq_container_filt(li, is_odd);
	std::cout << "----------------------------------" << std::endl;

	/* Template */
	vi.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	li.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	seq_container_filt<vector<int>>(vi, is_even); 
	seq_container_filt<list<int>>(li, is_odd);
	std::cout << "----------------------------------" << std::endl;

	/* Normal function calls */
	vi.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	li.assign(ia, ia + (sizeof(ia) / sizeof(*ia)));
	for (auto it = vi.cbegin(); it != vi.cend();) {
		if (*it % 2 == 0) {
			it = vi.erase(it);
		} else {
			++it;
		}
	}

	for (auto i : vi) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	for (auto it = li.cbegin(); it != li.end(); ) {
		if (*it % 2 != 0) {
			it = li.erase(it);
		} else {
			++it;
		}
	}

	for (auto i : li) {
		std::cout << i << ", ";
	}

	std::cout << std::endl;
}


