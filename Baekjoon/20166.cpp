#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

char grid[11][11];
unordered_map<string, int> m;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int N, M, K;

void dfs(int x, int y, string cur) {
	if (cur.length() > 5) return;
	m[cur]++;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= N) nx = 0;
		else if (nx < 0) nx = N - 1;
		if (ny >= M) ny = 0;
		else if (ny < 0) ny = M - 1;
		dfs(nx, ny, cur + grid[nx][ny]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			s = grid[i][j];
			dfs(i, j, s);
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> s;
		cout << m[s] << '\n';
	}
	return 0;
}
