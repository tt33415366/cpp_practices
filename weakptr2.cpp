/*
 * Because the cycle references exists, you might got leak here.
 *   g++ weakptr1.cpp -o weakptr1 -fsanitize=address -g
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
	public:
		string name;
		shared_ptr<Person> mother;
		shared_ptr<Person> father;
		vector<weak_ptr<Person>> kids; // Weak pointers

		Person(const string& n,
				shared_ptr<Person> m = nullptr,
				shared_ptr<Person> f = nullptr)
			: name(n), mother(m), father(f) {
			}
		~Person() {
			cout << "delete " << name << endl;
		}
};

shared_ptr<Person> initFamily(const string& name)
{
	shared_ptr<Person> mom(new Person(name + "'s mom"));
	shared_ptr<Person> dad(new Person(name + "'s dad"));
	shared_ptr<Person> kid(new Person(name, mom, dad));

	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}

int main()
{
	shared_ptr<Person> p = initFamily("nico");

	cout << "nico's family exists" << endl;
	cout << "- nico is shared " << p.use_count() << " times" << endl;
	cout << "- name of 1st kid of nico's mon: "
		<< p->mother->kids[0].lock()->name << endl; /* N.B. a lock is required here */

	p = initFamily("jim");
	cout << "jim's family exists" << endl;
}
