#include<iostream>
#include<string>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, a, b;
	string s1, s2;
	char *intStr;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int total = 0;
		s2 = "";
		cin >> a >> b;
		cin >> s1;
		for (int j = 0; j < s1.size(); j++) {
			total = (a*(s1[j] - 'A') + b) % 26;
			cout << total << '\n';
			s2 += (char)(total+'A');
		}
		cout << s2 << '\n';
	}
	return 0;
}