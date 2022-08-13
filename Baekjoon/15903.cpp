#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<long long, vector<long long>, greater<long long>> p;
	int n, m, tmp;
	long long sum = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		p.push(tmp);
	}
	
	for (int i = 0; i < m; i++) {
		long long fir = p.top();
		p.pop();
		long long sec = p.top();
		p.pop();
		p.push(fir + sec);
		p.push(fir + sec);
	}

	while (!p.empty()) {
		sum += p.top();
		p.pop();
	}
	cout << sum << '\n';
	return 0;
}
