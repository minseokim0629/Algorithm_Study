N = int(input())
M = int(input())
graph = [[] for x in range(N+1)]
visited = [False for i in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a]+=[b]
    graph[b]+=[a]

def dfs(v):
    visited[v]=True;
    for i in graph[v]:
        if visited[i]==False:
            dfs(i)

dfs(1)
print(sum(visited)-1)
