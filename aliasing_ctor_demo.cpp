#include <iostream>
#include <memory>

int main()
{
	struct X {
		int a;
	};
	std::shared_ptr<X> px(new X);
	{
		/* Beware of the `->` and `.` here:
		 * `->` is referenced to the real pointer, while 
		 * `.` is referencing to shared_ptr
		 */
		std::shared_ptr<int> pi(px, &px->a);
		std::cout << "After aliasing constructor, use count of px: " << px.use_count() << std::endl;
	}
	std::cout << "use count of px: " << px.use_count() << std::endl;
}
