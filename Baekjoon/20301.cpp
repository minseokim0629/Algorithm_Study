#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, M;
	deque<int> dq;
	vector<int> ans;
	bool reverse = false;
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (!reverse) {
			for (int j = 1; j < K; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			ans.push_back(dq.front());
			dq.pop_front();
		}
		else {// 반대
			for (int j = 1; j < K; j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans.push_back(dq.back());
			dq.pop_back();
		}

		if (i % M == 0) reverse = !reverse;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
