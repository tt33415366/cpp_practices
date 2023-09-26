/*
 * - All iterators are equality comparable.
 * - Only random access iterators are relationally comparable.
 * - Input iterators, forward iterators, and bidirectional iterators are not relationally comparable.
 *
 *  STL CONTAINER  |  ITERATOR SUPPORTED
 *
 *  Vector         |  Random-Access
 *
 *  List           |  Bidirectional
 *
 *  Dequeue        |  Random-Access
 *
 *  Map            |  Bidirectional
 *
 *  Multimap       |  Bidirectional
 *
 *  Set            |  Bidirectional
 *
 *  Multiset       |  Bidirectional
 *
 *  Stack          |  Does not support any iterator
 *
 *  Queue          |  Does not support any iterator
 *
 *  Priority-Queue |  Does not support any iterator
 */
#include <list>
#include <vector>

void foo()
{
	using std::list;

	list<int> lst;
	list<int>::iterator iter1 = lst.begin(), iter2 = lst.end();

	while (iter1 < iter2); /* Error:
				* g++ error: no match for ‘operator<’
				* clang++ error: invalid operands to binary expression
				*/
	using std::vector;

	vector<int> vec;
	vector<int>::iterator iter3 = vec.begin(), iter4 = vec.end();

	while (iter3 < iter4);
}
