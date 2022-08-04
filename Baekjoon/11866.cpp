#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, cur=0;
	vector<int> v;
	queue<int> q;
	cin >> N >> K;
	K -= 1;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	cur = K;
	for (int i = 0; i < N; i++) {
		q.push(v[cur]);
		v.erase(v.begin() + cur);
		if (v.empty()) break;
		cur = (cur + K) % v.size();
	}
	cout << "<";
	while (!q.empty()) {
		cout << q.front();
		if (q.size() > 1) cout << ", ";
		q.pop();
	}
	cout << ">" << '\n';
	return 0;
}
