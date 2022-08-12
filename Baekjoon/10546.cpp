#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	unordered_map<string, int> m;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s]++;
	}
	for (int i = 0; i < N-1; i++) {
		cin >> s;
		m[s]--;
	}
	for (auto elem : m) {
		if (elem.second) {
			cout << elem.first << '\n';
			break;
		}
	}
	return 0;
}
