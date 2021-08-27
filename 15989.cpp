#include<iostream>
using namespace std;

int dp[10001][3];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	cin >> T;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;

	for (int i = 2; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		if (i > 2)
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i > 3)
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	for (int i = 0; i < T; i++) {
		cin >> n;
		//cout << dp[n][1] << " " << dp[n][2] << " " << dp[n][3] << '\n';
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}
