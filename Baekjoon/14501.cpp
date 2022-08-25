#include<iostream>
#include<algorithm>
using namespace std;

int T[16];//걸리는 기간
int P[16];//받을 수 있는 금액
int dp[16];
int cur_max = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, t, p;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t >> p;
		T[i] = t;
		P[i] = p;
	}
	//N+1일째 퇴사를 하므로 N일동안 상담 후 N+1에 돈받기 가능
	for (int i = 1; i <= N + 1; i++) {
		cur_max = max(cur_max, dp[i]);
		if (i + T[i] > N + 1) continue;
		dp[i + T[i]] = max(dp[i + T[i]], cur_max + P[i]);
	}
	cout << cur_max << '\n';
	return 0;
}
