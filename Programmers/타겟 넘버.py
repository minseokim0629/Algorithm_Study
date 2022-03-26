def solution(numbers, target):
    answer = 0
    super = [0]
    
    for i in numbers:
        sub = []
        for j in super:
            sub.append(j + i)
            sub.append(j - i)
        super = sub
    
    answer = super.count(target)
    return answer
