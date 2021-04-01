#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> v;

bool compare(string s1, string s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	else
		return s1.size() < s2.size();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	string total;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		if (v[i] != total) {
			cout << v[i] << '\n';
			total = v[i];
		}
	}
	return 0;
}