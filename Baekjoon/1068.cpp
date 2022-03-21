#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[51];
int N, Root, Cut;

int dfs(int v) {
	int child = 0;
	int leaf = 1;

	for (auto&i : tree[v]) {
		if (i == Cut)
			continue;
		child += dfs(i);
	}

	if (child) return child; //leaf노드가 아닌 경우
	else return leaf; //leaf노드인 경우
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) 
			Root = i;
		else 
			tree[parent].push_back(i);
	}

	cin >> Cut;
	if (Cut == Root) cout << 0 << '\n';
	else cout << dfs(Root) << '\n';

	return 0;
}
