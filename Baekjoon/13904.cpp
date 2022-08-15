#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, d, w; // d - 과제마감일, w - 과제점수
	priority_queue<pair<int, int>> pq;
	bool visited[1001] = {};
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		pq.push({ w, d });
	}

	while (!pq.empty()) {
		int score = pq.top().first;
		int deadline = pq.top().second;
		pq.pop();
		for (int i = deadline; i >= 1; i--) {
			if (!visited[i]) {
				visited[i] = true;
				ans += score;
				break;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
