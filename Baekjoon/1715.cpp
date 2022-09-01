#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	int total = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	while (pq.size() > 1) {
		int fir = pq.top();
		pq.pop();
		int sec = pq.top();
		pq.pop();
		pq.push(fir + sec);
		total += fir + sec;
	}
	cout << total << '\n';
	return 0;
}
