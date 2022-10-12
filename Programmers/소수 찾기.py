from itertools import permutations

def prime_list(n):
    prime = [True] * (n+1)
    prime[0] = prime[1] = False
    for i in range(2, int(n**0.5) +1):
        if prime[i]:
            for j in range(i*2, n+1, i):
                prime[j] = False
    return prime

def solution(numbers):
    answer = 0
    numbers = list(numbers)
    numbers_set = set()
    
    for i in range(len(numbers)):
        numbers_set |= set(map(int, map(''.join, permutations(numbers, i+1))))
        
    prime = prime_list(max(numbers_set))

    for i in numbers_set:
        if prime[i] : answer+=1
    return answer
