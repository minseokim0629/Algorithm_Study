#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, S, T;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		v.push_back({ S, T });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (pq.empty()) pq.push(v[i].second);
		else {
			int fin = pq.top();
			if (v[i].first >= fin) pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << '\n';
	return 0;
}
