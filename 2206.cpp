//벽 부수고 이동하기
#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[1001][1001];
int result[1001][1001];
//벽 부순 적이 있는지 여부 체크
int visited[1001][1001][2];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
queue<pair<pair<int, int>, int>> q;
bool arrive = false;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny][wall])
            {
                //벽인데 벽을 부순 적이 없음
                if (map[nx][ny] == '1' && wall == 0)
                {
                    visited[nx][ny][wall + 1] = true;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({{nx, ny}, wall + 1});
                }
                //벽이 아님
                else if (map[nx][ny] == '0')
                {
                    visited[nx][ny][wall] = true;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({{nx, ny}, wall});
                }
                //도착 했을 경우
                if (nx == N - 1 && ny == M - 1)
                {
                    arrive = true;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
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
    q.push({{0, 0}, 0});
    result[0][0] = 1;
    BFS();
    if (arrive)
        cout << result[N - 1][M - 1] << '\n';
    else
    {
        if (N == 1 && M == 1)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}
