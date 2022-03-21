#include<iostream>

using namespace std;

long long dp[101][101];
int arr[101][101];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;
			
			int value = arr[i][j];
			int down = i + value;
			int right = j + value;

			if (down < N) dp[down][j] = dp[down][j] + dp[i][j];
			if (right < N) dp[i][right] = dp[i][right] + dp[i][j];
		}
	}

	cout << dp[N - 1][N - 1] << '\n';

	return 0;
}
