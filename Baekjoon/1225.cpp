#include<iostream>
#include<string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2;
	int i1, i2;
	long long result = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			i1 = s1[i] - '0';
			i2 = s2[j] - '0';
			result += (i1 * i2);
		}
	}
	cout << result << '\n';
	return 0;
}