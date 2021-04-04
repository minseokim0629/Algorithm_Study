#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int dp[2000] = {};
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	dp[0] = 1;
	for (int i = 1; i < v.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i] && dp[j] +1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
		count = max(count, dp[i]);
	}
	cout << n - count << '\n';
	return 0;
}