#include <iostream>
#include <memory>

class A {
	public:
		~A() {
			std::cout << __func__ << std::endl;
		}
};

int main()
{
	std::cout << "main block" << std::endl;
	{
		std::cout << "Enter sub block" << std::endl;
		std::unique_ptr<A> a(new A);
	}
	std::cout << "back to main block" << std::endl;
}
