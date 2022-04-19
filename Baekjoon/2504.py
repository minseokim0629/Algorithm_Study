#괄호의 값
s = input()
stk = []
tmp = 1
ans = 0

for i in range(len(s)):
    if(s[i] == '('):
        tmp *= 2
        stk.append(s[i])
    elif(s[i] == '['):
        tmp*=3
        stk.append(s[i])
    elif(s[i] == ')'):
        if not stk : stk.append(s[i])
        elif s[i-1] == '(':
            ans+=tmp
            stk.pop()
            tmp//=2 #몫
        elif stk[-1] == '(':
            stk.pop()
            tmp//=2
    elif(s[i] == ']'):
        if not stk : stk.append(s[i])
        elif s[i-1] == '[':
            ans+=tmp
            stk.pop()
            tmp//=3
        elif stk[-1] == '[':
            stk.pop()
            tmp//=3

if not stk:
    print(ans)
else:
    print(0)

