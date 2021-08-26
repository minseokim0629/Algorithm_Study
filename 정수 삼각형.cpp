#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int n = triangle.size();
	dp[0][0] = triangle[0][0];
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			int down_left = dp[i][j] + triangle[i + 1][j];
			int down_right = dp[i][j] + triangle[i + 1][j + 1];
			if (down_left > dp[i + 1][j])
				dp[i + 1][j] = down_left;
			if (down_right > dp[i + 1][j + 1])
				dp[i + 1][j + 1] = down_right;
			if (i == n - 2) {
				answer = max(answer, dp[n - 1][j]);
			}
		}
	}


	return answer;
}
