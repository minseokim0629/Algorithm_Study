#include<iostream>
using namespace std;

char map[1001][1001];
int visit[1001][1001];
int M, N, findPath = 0;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0, 1, -1,0 };

void dfs(int x, int y) {
	visit[x][y] = 1;
	if (x == M - 1) {
		findPath = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if (tmpx < 0 || tmpx >= M || tmpy < 0 || tmpy >= N)
			continue;
		if (visit[tmpx][tmpy] == 1 || map[tmpx][tmpy] == '1')
			continue;
		dfs(tmpx, tmpy);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (map[0][i] == '0')
			dfs(0, i);
	}
	if (findPath)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}
