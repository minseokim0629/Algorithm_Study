#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, parent;
vector<int> e[1000001];
int dp[1000001][2];//0이 어답터, 1이 일반인
bool visited[1000001];

void find(int x) {
	visited[x] = true;
	dp[x][0] = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int child = e[x][i];
		if (visited[child]) continue;
		find(child);
		//부모가 일반인이면 자식은 무조건 어답터
		dp[x][1] += dp[child][0];
		//부모가 어답터이면 자식이 어답터일 경우와 아닐 경우 중 
		//더 작은 값 선택
		dp[x][0] += min(dp[child][0], dp[child][1]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	find(1);
	cout << min(dp[1][0], dp[1][1]) << '\n';
	return 0;
}
