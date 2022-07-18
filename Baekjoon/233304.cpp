#include<iostream>
#include<string>
using namespace std;

bool palindrome(string s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	bool result = palindrome(s);


	if (result) 
		cout << "AKARAKA" << '\n';
	else 
		cout << "IPSELENTI" << '\n';

	return 0;
}

bool palindrome(string s) {
	int len = s.length();

	if (len == 1) return true;

	string left, right;

	for (int i = 0; i < len / 2; i++) {
		left += s[i];
	}

	for (int i = 0; i < len / 2; i++) {
		if (len % 2 == 1) right += s[i + len / 2 + 1];
		else right += s[i + len / 2];
	}

	if (left != right) return false;
	if (palindrome(left) && palindrome(right)) return true;
	return false;
}
