#include <string>
typedef std::string Type;
Type initVal();
class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal();
private:
	int val;
};

/*
 * error: prototype for ‘Type Exercise::setVal(Exercise::Type)’ does not match any in class ‘Exercise’
 * error: candidate is: Exercise::Type Exercise::setVal(Exercise::Type)
 */
// Type Exercise::setVal(Type parm) 
Exercise::Type Exercise::setVal(Type parm)
{
	val = parm + initVal();
	return val;
}
