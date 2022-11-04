#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

namespace impl {
	template <typename RandomIt, typename Compare = std::less<typename std::iterator_traits<RandomIt>::value_type>>
		void sift_down(RandomIt	begin, RandomIt end, const Compare &comp = {}) { // sift down element at "begin"
			const auto length = static_cast<size_t>(end - begin);
			size_t current = 0;
			size_t next = 2;
			while (next < length) {
				/* compared the two child */
				if (comp(*(begin + next), *(begin + (next - 1)))) {
					next--;
				}
				/* compared with the 'comp' true child */
				if (!comp(*(begin + current), *(begin + next))) {
					return ;
				}
				std::iter_swap(begin + current, begin + next);
				current = next;
				next = 2 * current + 2;
			}
			--next;
			if (next < length && comp(*(begin + current), *(begin + next))) {
				std::iter_swap(begin + current, begin + next);
			}
		}

	template <typename RandomIt, typename Compare = std::less<typename std::iterator_traits<RandomIt>::value_type>>
		void heap_select(RandomIt begin, RandomIt middle, RandomIt end, const Compare &comp = {}) {
			std::make_heap(begin, middle, comp);
			for (auto i = middle; i != end; i++) {
				if (comp(*i, *begin)) {
					std::iter_swap(begin, i);
					sift_down(begin, middle, comp);
				}
			}
		}
} // namespace impl

template <typename RandomIt, typename Compare = std::less<typename std::iterator_traits<RandomIt>::value_type>>
void partial_sort(RandomIt begin, RandomIt middle, RandomIt end, Compare comp = {}) {
	impl::heap_select(begin, middle, end, comp);
	std::sort_heap(begin, middle, comp);
}


int main()
{
	std::vector<int> vec = {1, 9, 3, 7, 8, 4, 2, 5, 6, 6};
	::partial_sort(vec.begin(), vec.begin() + 5, vec.end());
	for (auto v : vec) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}
