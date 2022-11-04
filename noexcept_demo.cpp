#include <exception>

void foo() noexcept {
	throw 43; // 'foo' has a non-throwing exception specification but can still throw
			  // This will effectively generate a call to std::terminate
}

int main()
{
	try {
		foo();
	} catch (std::exception &e) {
	}
}

