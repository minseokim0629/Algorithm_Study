#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
vector<vector<char>> v;
void dfs(int x, int y);
bool visited[601][601] = { false };
int result = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char tmp;
		vector<char> c;
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 'I') {
				x = i;
				y = j;
			}
			c.push_back(tmp);
		}
		v.push_back(c);
	}
	
	dfs(x, y);
	if (result == 0)
		cout << "TT" << '\n';
	else
		cout << result << '\n';

	return 0;
}

void dfs(int x, int y) {
	visited[x][y] = true;
	if (v[x][y] == 'P')
		result++;
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visited[nx][ny]) {
				if (v[nx][ny] != 'X')
					dfs(nx, ny);
			}
		}
	}
}
