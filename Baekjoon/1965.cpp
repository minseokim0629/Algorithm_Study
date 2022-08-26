#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int box[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}
