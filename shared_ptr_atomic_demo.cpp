#include <ios>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

std::shared_ptr<int> global; // initially empty

int foo1()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::shared_ptr<int> local {new int(10)};

	(*local)++;

	std::atomic_store(&global, local);
	while (true) {
		(*local)++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int foo2()
{
	std::cout << std::boolalpha << "Atomic is lock free: " << std::atomic_is_lock_free(&global) << std::endl;;
	while (true) {
		std::shared_ptr<int> local = std::atomic_load(&global);
		if (local)
			std::cout << *local << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main()
{
	std::thread t1(foo1);
	std::thread t2(foo2);

	t1.join();
	t2.join();
}

