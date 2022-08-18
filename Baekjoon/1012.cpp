#include<iostream>
#include<cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
int T, M, N, K;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	if (!map[x][y] || visited[x][y])
		return;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int X, Y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
