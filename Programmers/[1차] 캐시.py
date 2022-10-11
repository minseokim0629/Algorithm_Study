from collections import deque

def solution(cacheSize, cities):
    answer = 0
    dq = deque() #초기화
    if cacheSize==0 :
        return len(cities) * 5
    else :
        for i in cities:
            i = i.lower() #대소문자 구분 하지 않으므로
            if i in dq : answer+=1
            else : answer+=5
            
            if i in dq:
                dq.remove(i)
            else:
                if len(dq) >= cacheSize:
                    dq.popleft()
            
            dq.append(i)
    return answer
