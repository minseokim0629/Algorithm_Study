#include<iostream>
using namespace std;

int arr[101][101];
bool visited[101];
int cnt = 0;
int N, M;

void dfs(int cur) {
	visited[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (cur != i && !visited[i] && arr[cur][i]) {
			cnt++;
			dfs(i);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(1);
	cout << cnt << '\n';
	return 0;
}
