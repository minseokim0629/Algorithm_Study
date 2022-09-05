#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<string> v;
	vector<int> idx(26);
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		int cal = 1;
		for (int j = v[i].length() - 1; j >= 0; j--) {
			idx[v[i][j] - 'A'] += cal;
			cal *= 10;
		}
	}
	sort(idx.begin(), idx.end(), cmp);
	int cur = 9;
	for (int i = 0; i < 10; i++) {
		ans += idx[i] * cur;
		cur--;
	}
	cout << ans << '\n';
	return 0;
}
