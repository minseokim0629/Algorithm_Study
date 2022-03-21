#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	while (1) {
		bool b = true;
		stack<char> c;
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[')
				c.push(s[i]);
			else if (s[i] == ')') {
					if (c.size()!=0&&c.top() == '(')
						c.pop();
				else {
					b = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (c.size()!=0&&c.top() == '[')
					c.pop();
				else {
					b = false;
					break;
				}
			}
		}
		if (b&&c.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}