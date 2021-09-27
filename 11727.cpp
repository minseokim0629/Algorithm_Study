#include <iostream>
using namespace std;

int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < N; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    cout << dp[N - 1] << '\n';
    return 0;
}
