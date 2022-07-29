#include <iostream>
#include <memory>

using namespace std;
int main()
{
	std::shared_ptr<int> sp(new int(8), 
			[] (int *p) {
			cout << "delete " << *p << endl;
			throw 30;
			delete p;
			});

}

