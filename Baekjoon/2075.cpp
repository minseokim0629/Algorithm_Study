#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, tmp;
	priority_queue<int, vector<int>, greater<int>> pq; //오름차순

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			pq.push(tmp);
			if (pq.size() > N) {
				pq.pop();
			}
		}
	}
	cout << pq.top() << '\n';
	return 0;
	
}
