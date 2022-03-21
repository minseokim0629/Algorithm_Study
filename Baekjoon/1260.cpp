#include<iostream>
#include<queue>
using namespace std;

int mat[1001][1001];
int visit[1001];
int n, m, v;

void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1 || mat[v][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	visit[v] = 0;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		cout << v << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 || mat[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		mat[x][y] = mat[y][x] = 1;
	}
	dfs(v);
	cout << '\n';
	bfs(v);
	cout << '\n';
}
