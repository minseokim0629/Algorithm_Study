#include<iostream>
#include<queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T, N, M, x, index;
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int count = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> x;
			q.push({ x, j });
			pq.push(x);
		}

		while (1) {
			x = q.front().first;
			index = q.front().second;
			q.pop();
			if (pq.top() == x) {
				count++;
				pq.pop();
				if (index == M)
				{
					cout << count << '\n';
					break;
				}
			}
			q.push({ x, index });
		}
	}
		return 0;
}