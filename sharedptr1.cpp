#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
void dump_vec(vector<shared_ptr<string>> &whoMadeCoffee) {
	// print all elments
	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;
}

int main() {
	// two shared pointers representing two persons by their name
	shared_ptr<string> pNico(new string("nico"),
			[](string* p) {
				cout << "delete " << *p << endl;
				delete p;
			});
	// It's prefered the following format, it causes only one memory
	// allocations.
	shared_ptr<string> pJutta = make_shared<string>("jutta");
	// g++ sharedptr1.cpp -o sharedptr1 -fsanitize=address -g, 
	// g++ is required to be larger than or equal to 4.8
	string *p = new string("leaking...");

	// capitalize person names
	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	// put them multiple times in a container
	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	dump_vec(whoMadeCoffee);
	
	// overwrite a name again
	*pNico = "Nicolai";

	dump_vec(whoMadeCoffee);
	// print some internal data
	cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}
