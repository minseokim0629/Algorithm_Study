N = int(input())

for i in range(N):
    s = input()
    VPS = list(s)
    sum = 0
    for j in VPS:
        if j=='(':
           sum+=1
        else:
            sum -=1
        if sum<0:
            print("NO")
            break
    
    if sum>0:
        print("NO")
    elif sum==0: 
        print("YES")
                
