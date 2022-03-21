이분탐색

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		cin >> N >> M;
		vector<int> v1(N);
		vector<int> v2(M);

		for (auto &j : v1)
		{
			cin >> j;
		}
		for (auto &j : v2) {
			cin >> j;
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		for (auto i : v1) {
			ans += lower_bound(v2.begin(), v2.end(), i) - v2.begin();
		}
		cout << ans << '\n';
	}
	return 0;
}
