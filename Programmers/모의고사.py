def solution(answers):
    answer = []
    a1 = [1, 2, 3, 4, 5]
    a2 = [2, 1, 2, 3, 2, 4, 2, 5]
    a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    s1, s2, s3 = 0, 0, 0
    
    for i in range(len(answers)):
        if a1[i%5] == answers[i] : s1+=1
        if a2[i%8] == answers[i] : s2+=1
        if a3[i%10] == answers[i] : s3+=1

    k = max(s1, s2, s3)
    
    if(k==s1) :
        answer.append(1)
    if(k==s2) : 
        answer.append(2)
    if(k==s3) :
        answer.append(3)
    return answer
