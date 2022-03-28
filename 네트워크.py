def dfs(computers, cur):
    if computers[cur][cur]==0:
        return False
    computers[cur][cur]=0
    for i in range(len(computers[cur])):
        if computers[cur][i]: 
            dfs(computers,i)
    return True
    

def solution(n, computers):
    answer = 0
    for i in range(n):
        if computers[i][i] and dfs(computers,i):
            answer+=1
            
    return answer
