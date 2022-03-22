from heapq import *

def solution(scoville, K):
    cnt = 0
    heapify(scoville)
    while scoville[0] < K and len(scoville) > 1:
        num1 = heappop(scoville)
        num2 = heappop(scoville)
        heappush(scoville, num1 + num2 * 2)
        cnt += 1
    if scoville[0] > K :
        return cnt
    else : 
        return -1
