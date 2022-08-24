#include<iostream>
#include<queue>
using namespace std;

int map[101];
bool visited[101];

void bfs() {
	queue<pair<int, int>> q;
	visited[1] = true;
	q.push({ 1, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;//주사위 굴린 횟수
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = cur + i;
			if (nx == 100) {
				cout << cnt + 1 << '\n';
				return;
			}
			while (map[nx]) {
				nx = map[nx];
			}
			if (!visited[nx]) {
				visited[nx] = true;
				q.push({ nx, cnt + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, x, y, u, v;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		map[x] = y;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		map[u] = v;
	}
	bfs();
	return 0;
}
