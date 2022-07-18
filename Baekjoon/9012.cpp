#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		bool VPS = true;
		stack<char> stk;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				stk.push(s[i]);
			else {
				if (!stk.empty()) {
					if (stk.top() == '(')
						stk.pop();
				}
				else {
					VPS = false;
					break;
				}
			}
		}

		if (VPS && stk.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}
