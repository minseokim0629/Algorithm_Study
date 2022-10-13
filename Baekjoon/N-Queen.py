def dfs(queen, n, cur_row):
    cnt = 0
    if(cur_row == n):
        return 1
    for i in range(n):
        queen[cur_row] = i #i = row, i = column
        #for-else 구문
        for j in range(cur_row):
            if queen[j] == queen[cur_row] : #같은 열에 위치
                break
            if abs(queen[j] - queen[cur_row]) == cur_row - j : # 대각선
                break
        else:
            cnt += dfs(queen, n, cur_row + 1)
    return cnt #0          

def solution(n):
    answer = 0
    queen = [0] * (n+1)
    answer = dfs(queen, n, 0)
    return answer
