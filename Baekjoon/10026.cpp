#include<iostream>
#include<cstring>
using namespace std;

char arr[101][101];
bool isvisited[101][101];
int cnt = 0;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

void dfs(int x, int y) {
	isvisited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!isvisited[nx][ny] && arr[x][y] == arr[nx][ny]) {
			dfs(nx, ny);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isvisited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	memset(isvisited, false, sizeof(isvisited));

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isvisited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
