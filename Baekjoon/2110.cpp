#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, C, ans = 0;
    cin >> N >> C;
    vector<int> v(N);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());

    //최소값은 v[0]으로 하면 안됨.
    // 반례 : 2 2 10 11
    int start = 1;
    int end = v[N - 1];

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 1;
        int standard = v[0]; //기준
        //cout << "mid: " << mid << '\n';
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - standard >= mid)
            {
                cnt++;
                standard = v[i];
            }
        }
        //cout << cnt << '\n';
        if (cnt >= C)
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
