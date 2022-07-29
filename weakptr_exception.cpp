#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	try {
		shared_ptr<string> sp(new string("hi")); /* Create a shared pointer */
		weak_ptr<string> wp = sp; /* Create weak pointer out of a shared pointer */
		sp.reset(); /* release object of shared pointer */
		cout << wp.use_count() << endl; /* prints 0 */
		cout << boolalpha << wp.expired() << endl; /* throws std::bad_weak_ptr */
		shared_ptr<string> p(wp); /* throws std::bad_weak_ptr */
	} catch (const std::exception& e) {
		cerr << "exception: " << e.what() << endl; // prints: bad_weak_ptr
	}
}

