#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, tmp;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int close = abs(v[0] + v[v.size() - 1]);
    int left = 0;
    int right = v.size() - 1;
    int fir = v[0];
    int sec = v[v.size() - 1];

    while (left < right)
    {
        tmp = v[left] + v[right];
        if (abs(tmp) < close)
        {
            close = abs(tmp);
            fir = v[left];
            sec = v[right];
        }

        if (tmp < 0)
            left++;
        else
            right--;
    }

    cout << fir << " " << sec << '\n';
    return 0;
}
