//오큰수
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp;
    vector<int> v;
    vector<int> ans;
    stack<int> stk;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        v.push_back(tmp);
    }

    ans.resize(N, -1);

    for(int i=0; i<v.size(); i++){
       while(!stk.empty() && v[i] > v[stk.top()]){
           ans[stk.top()] = v[i];
           stk.pop();
       }
       stk.push(i);
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
