def solution(clothes):
    answer = 1
    fashion = {}
    
    for cloth, type in clothes:
        fashion[type] = fashion.get(type, 0) + 1
    
    for type in fashion:
        answer *= (fashion[type] +1)
        
    return answer-1
