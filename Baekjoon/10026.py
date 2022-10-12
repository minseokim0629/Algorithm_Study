from collections import deque

N=int(input())
arr = [[] for _ in range(N)]
visited = [[False]*N for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
cnt = 0

for i in range(N):
    color = str(input())
    for x in color:
        arr[i].append(x)

def bfs(x, y):
    dq=deque()
    dq.append([x, y])

    while dq:
        cur = dq.popleft()
        fir = cur[0]
        sec = cur[1]
        for i in range(4):
            nx = dx[i] + fir
            ny = dy[i] + sec
            if nx>=0 and ny>=0 and nx<N and ny<N :
                if visited[nx][ny] == False and arr[nx][ny] == arr[fir][sec]:
                    visited[nx][ny] = True
                    dq.append([nx, ny])

for i in range(N):
    for j in range(N):
        if visited[i][j]==False:
            bfs(i, j)
            cnt+=1

for i in range(N):
    for j in range(N):
        if arr[i][j]=='G':
            arr[i][j]='R'
print(cnt)
visited = [[False]*N for _ in range(N)]
cnt=0
for i in range(N):
    for j in range(N):
        if visited[i][j]==False:
            bfs(i, j)
            cnt+=1
print(cnt)
