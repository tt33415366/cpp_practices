#include <regex>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	using namespace std;

	string s("this subject has a submarine as a subsequence");
	smatch m;
	regex e("\\b(sub)([^ ]*)"); // Matches words begin with "sub".

	cout << "Target sequence: " << s << endl;
	cout << "Regular expression: /\\b(sub)([^ ]*)/" << endl;
	cout << "The following matches and submatches were found:" << endl;

	while (regex_search(s, m, e)) {
		for (auto x : m) {
			cout << x << " ";
		}
		cout << endl;
		s = m.suffix().str();
	}


	cout << "Using sregex_iterator: " << endl;
	string s1("this subject has a submarine as a subsequence");
	auto sendi = sregex_iterator();
	for (auto i = sregex_iterator(s1.begin(), s1.end(), e); i != sendi; i++) {
		for (auto x : *i) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
