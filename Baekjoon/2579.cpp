//계단 오르기
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int dp[301];
int cnt = 0;
long long total = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[0] = v[0];
    dp[1] = max(v[1], v[0] + v[1]);
    dp[2] = max(v[0] + v[2], v[1] + v[2]);

    for (int i = 3; i < N; i++)
    {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }
    cout << dp[N - 1] << '\n';
    return 0;
}
