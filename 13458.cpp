// 백준 시험 감독
#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, B, C;
    long long total = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    cin >> B >> C;
    for (int i = 0; i < N; i++)
    {
        A[i] -= B;
        total++;
        if (A[i] > 0)
        {
            total += (A[i] / C);

            if (A[i] % C > 0)
                total++;
        }
    }
    cout << total << '\n';
    return 0;
}
