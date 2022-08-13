#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, ans = 0;
	unordered_map<string, int> m;
	string s;
	vector<int> fin(1001);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> s;
		fin[i] = m[s];
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (fin[i] > fin[j]) { //추월했다는 의미
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
