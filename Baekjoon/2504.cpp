#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string str;
    stack<char> stk;
    int answer=0;
    int tmp=1;
    cin>>str;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='('){
            tmp*=2;
            stk.push(str[i]);
        }
        else if(str[i]=='['){
            tmp*=3;
            stk.push(str[i]);
        }
        else if(str[i]==')'){
            if(stk.empty()) stk.push(str[i]);
            else if(str[i-1]=='('){ //묶음 계산
                answer+=tmp;
                stk.pop();
                tmp/=2;
            }
            else if(stk.top()=='('){ //이미 계산 완료
                stk.pop();
                tmp/=2;
            }
        }
        else if(str[i]==']'){
            if(stk.empty()) stk.push(str[i]);
            else if(str[i-1]=='['){
                answer+=tmp;
                stk.pop();
                tmp/=3;
            }
            else if(stk.top()=='['){
                stk.pop();
                tmp/=3;
            }
        }
    }

    if(stk.empty()) cout<<answer<<'\n';
    else cout<<0<<'\n';
    
    return 0;
}
