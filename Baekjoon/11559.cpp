#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char board[12][6];
bool bomb = false;
int result = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[12][6];

bool bfs(int x, int y, char c) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	memset(visited, false, sizeof(visited));
	q.push({ x, y });
	v.push_back({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && !visited[nx][ny]) {
				if (board[nx][ny] == c) {
					q.push({ nx, ny });
					v.push_back({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}

	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); i++) {
			board[v[i].first][v[i].second] = '.';
		}
		return true;
	}

	return false;
}

void down() {
	for (int i = 0; i < 6; i++) {
		queue<char> q;
		for (int j = 11; j >= 0; j--) {
			if (board[j][i] != '.') {
				q.push(board[j][i]);
			}
		}
		int qs = q.size();
		for (int j = 11; j >= 12 - qs; j--) {
			board[j][i] = q.front();
			q.pop();
		}
		for (int j = 12 - qs - 1; j >= 0; j--) {
			board[j][i] = '.';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		bomb = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					if (bfs(i, j, board[i][j])) {
						bomb = true;
					}
				}
			}
		}
		if (bomb) {
			result++;
			down();
		}
		else {
			break;
		}

	}
	cout << result << '\n';
	return 0;
}
