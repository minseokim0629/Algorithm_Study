def solution(brown, yellow):
    answer = [] #리스트
    width=0 
    height=0
    total=0
    
    for i in range(1, yellow+1):
        if yellow%i==0:
            width = yellow/i
            height = i
            total = width*2 + height*2 + 4
            if total == brown :
                answer.append(width + 2)
                answer.append(height + 2)
                answer.sort(reverse=True)
                break
                
    return answer
