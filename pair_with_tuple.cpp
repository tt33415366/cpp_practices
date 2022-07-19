/*
 * namespace std {
 *    template <typename T1, typename T2>
 *    struct pair {
 *        ...
 *        pair(const T1& x, const T2& y);
 *        template<typename U, typename V> pair(U&& x, V&& y);
 *        template <typename... Args1, typename... Args2>
 *          pair(piecewise_construct_t,
 *               tuple<Args1...> first_args,
 *               tuple<Args2...> second_args);
 *        ...
 *    };
 * }
 *
 * Normally, by passing one or two tuples, the first two constructors would allow initializing a pair, 
 * where first and/or second are tuples. 
 * But the third constructor uses the tuples to pass their `elements` to the constructors of first and
 * second. 
 * To force this behavior, you have to pass std::piecewise_construct as an additional first argument.
 */
#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

class Foo {
	public:
		Foo(tuple<int, float>) {
			cout << "Foo::Foo(tuple)" << endl;
		}
#if 0
		/*
		 *  If provided, a constructor Foo::Foo(int,float) would be called.
		 */
		Foo(int, float) {
			cout << "Foo::Foo(int, float)" << endl;
		}
#endif
		template <typename ... Args>
		Foo (Args ... args) {
			cout << "Foo::Foo(args...)" << endl;
		}
};

int main()
{
	// create tuple t
	tuple<int, float> t(1, 2.22);

	// pass the tuple as a whole to the constructor of Foo
	pair <int, Foo> p1 (42, t);

	// pass the `elements` of the tuple to the constructor of Foo
	// Only where std::piecewise_construct is passed as the first argument is class Foo forced to use a 
	// constructor that takes the elements of the tuple (an int and a float) rather than a tuple as a whole.
	pair<int, Foo> p2(piecewise_construct, make_tuple(42), t);
}
