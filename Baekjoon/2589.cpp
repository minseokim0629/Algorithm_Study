#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

char map[51][51];
bool visited[51][51];
queue<pair<pair<int, int>, int>> q;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
int N, M, ans = 0;

void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ { x, y }, 0 });

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 'W') continue;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ {nx, ny},t + 1 });
				ans = max(ans, t + 1);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				bfs(i, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
