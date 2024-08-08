#include<iostream>
#include<string>
#include<cctype>

void transformString(std::string& s);


int main() {
	using namespace std;
	string str;
	while (1) {
		cout << "Enter a string (q to quit): ";
		getline(cin, str);
		if (str == "q") {
			break;
		}
		transformString(str);
		cout << str << endl;
	}

	return 0;
}

void transformString(std::string& s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		s[i] = toupper(s[i]);
	}
}