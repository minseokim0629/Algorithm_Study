#include <iostream>
#include <queue>
using namespace std;

int board[21][21];
int copy_board[21][21];
int N, Max = 0;
int Select[5];

void Copy()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copy_board[i][j] = board[i][j];
        }
    }
}

void Shift()
{
    //5번 이동이니 for문 들어가기 전에 복사
    Copy();
    for (int i = 0; i < 5; i++)
    {
        queue<int> q;
        switch (Select[i])
        {
        case 0: //East
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (copy_board[i][j] != 0)
                        q.push(copy_board[i][j]);
                    copy_board[i][j] = 0;
                }

                int index = 0;
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    if (copy_board[i][index] == 0)
                        copy_board[i][index] = cur;
                    else if (copy_board[i][index] == cur)
                    {
                        copy_board[i][index++] *= 2; //합치는거 1번밖에 안되니까
                    }
                    else
                    {
                        copy_board[i][++index] = cur;
                    }
                }
            }
            break;
        case 1: //West
            for (int i = 0; i < N; i++)
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (copy_board[i][j] != 0)
                        q.push(copy_board[i][j]);

                    copy_board[i][j] = 0;
                }

                int index = N - 1;
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    if (copy_board[i][index] == 0)
                        copy_board[i][index] = cur;
                    else if (copy_board[i][index] == cur)
                    {
                        copy_board[i][index--] *= 2;
                    }
                    else
                    {
                        copy_board[i][--index] = cur;
                    }
                }
            }
            break;
        case 2:
            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if (copy_board[i][j] != 0)
                        q.push(copy_board[i][j]);

                    copy_board[i][j] = 0;
                }

                int index = 0;
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    if (copy_board[index][j] == 0)
                        copy_board[index][j] = cur;
                    else if (copy_board[index][j] == cur)
                    {
                        copy_board[index++][j] *= 2;
                    }
                    else
                    {
                        copy_board[++index][j] = cur;
                    }
                }
            }
            break;
        case 3:
            for (int j = 0; j < N; j++)
            {
                for (int i = N - 1; i >= 0; i--)
                {
                    if (copy_board[i][j] != 0)
                        q.push(copy_board[i][j]);

                    copy_board[i][j] = 0;
                }

                int index = N - 1;
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    if (copy_board[index][j] == 0)
                        copy_board[index][j] = cur;
                    else if (copy_board[index][j] == cur)
                    {
                        copy_board[index--][j] *= 2;
                    }
                    else
                    {
                        copy_board[--index][j] = cur;
                    }
                }
            }
            break;
        }
    }
}

void Find_Max()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (copy_board[i][j] > Max)
                Max = copy_board[i][j];
        }
    }
}

void dfs(int cnt)
{
    if (cnt == 5)
    {
        Shift();
        Find_Max();
        return;
    }

    //direction
    for (int i = 0; i < 4; i++)
    {
        Select[cnt] = i;
        dfs(cnt + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << Max << '\n';
    return 0;
}
