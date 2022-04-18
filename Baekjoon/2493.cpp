#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    vector<int> v;
    stack<pair<int, int>> s;
    cin>>N;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<v.size(); i++){
        if(s.empty()) {
            s.push({v[i], i});
            cout<<0<<" ";
        }
        else{
            while(!s.empty()){
                if(s.top().first >= v[i]){
                    cout<<s.top().second + 1<<" ";
                    break;
                }
                else
                    s.pop();
            }
            if(s.empty()) cout<<0<<" ";

            s.push({v[i], i});
        }
    }
    cout<<'\n';
    return 0;
}
