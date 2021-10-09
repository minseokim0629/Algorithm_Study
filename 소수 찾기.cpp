#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//에스트라토네스의 체
bool check(int i){
    if(i<2) return false;
    for(int j=2; j<=sqrt(i); j++){
        if(i%j==0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    vector<int> ans;
    for(int i=0; i<numbers.size(); i++){
        v.push_back(numbers[i]-'0');
    }
    //next_permutation 사용 위해 정렬 필요
    sort(v.begin(), v.end());
    
    do{
        for(int i=1; i<=v.size(); i++){
            int tmp=0;
            for(int j=0; j<i; j++){
                tmp=(tmp*10)+v[j];
                ans.push_back(tmp);
            }
        }
    }
    while(next_permutation(v.begin(), v.end()));

    sort(ans.begin(), ans.end());
    //중복 원소 제거
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(int i=0; i<ans.size(); i++){
        if(check(ans[i])) answer++;
    }
    return answer;
}
