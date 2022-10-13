def solution(s):
    answer = 0
    result = []
    if(len(s)==1) : #문자열 길이 1일 때 예외처리
        return 1
    for i in range(1, len(s)//2 +1):
        b = ''
        cnt = 1
        tmp = s[:i]
        for j in range(i, len(s), i):
            if tmp == s[j:j+i]:
                cnt+=1
            else:
                if cnt!=1:
                    b+=str(cnt)+tmp
                    cnt=1
                else:
                    b+=tmp
                tmp = s[j:j+i]
        if cnt!=1:
            b+=str(cnt)+tmp
        else:
            b+=tmp
        result.append(len(b))
    answer = min(result)        
    return answer
