#include<iostream>

using namespace std;

int dp[1500010];
int arr[1500010][2];

int bigger(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	int current_max = 0;

	for (int i = 1; i <= N + 1; i++) {
		current_max = bigger(current_max, dp[i]);
		if (i + arr[i][0] > N + 1) continue;
		dp[i + arr[i][0]] = bigger(current_max + arr[i][1], dp[i + arr[i][0]]);
	}
	int answer = current_max;
	cout << current_max << '\n';
	return 0;
}
