#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<pair<int, string>> v;

bool compare(pair<int, string> p1, pair<int, string> p2) {
	return p1.first < p2.first;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, age;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> s;
		v.push_back({ age, s });
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}