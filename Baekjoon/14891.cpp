#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

//N : 0, S : 1
vector<deque<int>> wheels(4);
bool visited[4];
int dir[4];
void dfs(int num, int d)
{
    dir[num] = d;
    visited[num] = true;

    if (num - 1 >= 0 && !visited[num - 1])
    {
        if (d == 0 || wheels[num][6] == wheels[num - 1][2])
            dfs(num - 1, 0);
        else
        {
            dfs(num - 1, d * (-1));
        }
    }

    if (num + 1 < 4 && !visited[num + 1])
    {
        if (d == 0 || wheels[num][2] == wheels[num + 1][6])
            dfs(num + 1, 0);
        else
        {
            dfs(num + 1, d * (-1));
        }
    }
}

void rotate()
{
    for (int i = 0; i < 4; i++)
    {
        if (dir[i] == 1)
        {
            int tmp = wheels[i].back();
            wheels[i].pop_back();
            wheels[i].push_front(tmp);
        }
        else if (dir[i] == -1)
        {
            int tmp = wheels[i].front();
            wheels[i].pop_front();
            wheels[i].push_back(tmp);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int K, N, D;
    char c;
    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            wheels[i].push_back(c - '0');
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> N >> D;
        for (int j = 0; j < 4; j++)
        {
            visited[j] = false;
        }
        dfs(N - 1, D);
        rotate();
    }

    for (int i = 0; i < 4; i++)
    {
        if (wheels[i].front() == 1)
            score += pow(2, i);
    }
    cout << score << '\n';
    return 0;
}
