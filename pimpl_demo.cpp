#include <iostream>
#include <memory>

class A {
public:
	A(int no, char c);
	void set_no(int no);
	friend std::ostream &operator << (std::ostream &os, const A& obj);
	~A();

protected:
	class impl; std::unique_ptr<impl> pimpl;
};

class A::impl {
public:
	impl(int no, char c): i(no), ch(c) {
		std::cout << __func__ << ": " << *this << std::endl;
	}
	void set_no(int no) {
		this->i = no;
	}
	friend std::ostream &operator << (std::ostream &os, const A::impl &obj) {
		os << "(" << obj.i << ", " << obj.ch << ")";
		return os;
	}
	~impl() {
		std::cout << __func__ << std::endl;
	}
private:
	int i;
	char ch;
};

A::A(int no, char c) {
	// pimpl = std::make_unique<impl>(no, c); // Since C++14
	pimpl = std::unique_ptr<impl>(new impl{no, c});
	std::cout << __func__ << ": " << *pimpl << std::endl;
}
void A::set_no(int no) {
	pimpl->set_no(no);
}
std::ostream &operator << (std::ostream &os, const A& obj) {
	os << *obj.pimpl;
	return os;
}
A::~A() {
}
static A a(3, 'a');

int main()
{
	std::cout << __func__ << ": " << a << std::endl;
	operator << (std::cout, a);
	// A::set_no(&a, 32); // error: no matching function for call to ‘A::set_no(A*, int)’
			   // candidate: void A::set_no(int no)
}
