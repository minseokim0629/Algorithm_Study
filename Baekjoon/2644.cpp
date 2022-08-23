#include<iostream>
#include<queue>
using namespace std;

int depth[101];
int family[101][101];
bool visited[101];
int n;
queue<int> q;
void bfs(int cur) {
	visited[cur] = true;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && family[cur][i]) {
				visited[i] = true;
				depth[i] = depth[cur] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, m;
	int x, y;
	cin >> n >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		family[x][y] = 1;
		family[y][x] = 1;
	}
	bfs(a);
	if (depth[b]) cout << depth[b] << '\n';
	else cout << -1 << '\n';
	return 0;
}
