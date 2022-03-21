//연구소
#include <iostream>
#include <queue>
using namespace std;

int map[9][9];
int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int answer = 0;

//지도 복사
void mapcopy(int (*a)[9], int (*b)[9])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

//바이러스 퍼뜨리기(BFS)
void virusSpread()
{
    int Spreadmap[9][9];
    mapcopy(Spreadmap, map);
    queue<pair<int, int>> q;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Spreadmap[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < M)
            {
                if (Spreadmap[nextx][nexty] == 0)
                {
                    Spreadmap[nextx][nexty] = 2;
                    q.push({nextx, nexty});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Spreadmap[i][j] == 0)
                cnt++;
        }
    }
    answer = max(answer, cnt);
}

//벽 세우기
void wall(int cnt)
{
    if (cnt == 3)
    {
        virusSpread();
        return;
    }
    //벽 세우기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                wall(cnt + 1);
                // 모든 경우를 고려해야 하므로 끝나면 다시 되돌려주기
                map[i][j] = 0;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                wall(1);
                map[i][j] = 0;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}