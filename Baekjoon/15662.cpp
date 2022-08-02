#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<string>
using namespace std;

//N : 0, S : 1
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, K, tmp, answer = 0;
	string s;
	deque<int> dq[1001];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			dq[i].push_back(s[j]-'0');
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, dir;
		vector<pair<int, int>> v; // 회전할 톱니바퀴
		queue<pair<int, int>> q;
		vector<bool>visited(1001);
		cin >> num >> dir;
		v.push_back({ num - 1, dir });
		q.push({ num - 1, dir });
		visited[num - 1] = true;
		while (!q.empty()) {
			int cur = q.front().first;
			int d = q.front().second;
			q.pop();
			
			//왼쪽 오른쪽 방문 여부도 체크 필요
			//왼쪽
			if (cur != 0) {
				if (dq[cur][6] != dq[cur - 1][2] && !visited[cur - 1]) {
					visited[cur - 1] = true;
					v.push_back({ cur - 1, d * (-1) });
					q.push({ cur - 1, d * (-1) });
				}
			}
			//오른쪽
			if (cur != T - 1) {
				if (dq[cur][2] != dq[cur + 1][6] && !visited[cur + 1]) {
					visited[cur + 1] = true;
					v.push_back({ cur + 1, d * (-1) });
					q.push({ cur + 1, d * (-1) });
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			int cur = v[j].first;
			int d = v[j].second;

			if (d == 1) { //시계방향
				tmp = dq[cur].back();
				dq[cur].pop_back();
				dq[cur].push_front(tmp);
			}
			else { //반시계방향
				tmp = dq[cur].front();
				dq[cur].pop_front();
				dq[cur].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < T; i++) {
		if (dq[i].front() == 1)
			answer++;
	}
	cout << answer << '\n';
	return 0;
}
