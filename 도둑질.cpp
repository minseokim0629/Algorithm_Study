#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[1000003]; // 1번째 집을 터는 경우(마지막 집을 털지 않는 경우)
int dp2[1000003]; // 1번째 집을 털지 않는 경우(마지막 집을 터는 경우)

int solution(vector<int> money) {
    int answer = 0;
    dp1[1]=money[0];
    dp1[2]=dp1[1];
    dp2[1]=0;
    dp2[2]=money[1];
    
    for(int i=3; i<money.size(); i++){
        dp1[i]+=max(dp1[i-2]+money[i-1], dp1[i-1]);
    }
    
    for(int i=3; i<=money.size(); i++){
        dp2[i]+=max(dp2[i-2]+money[i-1], dp2[i-1]);
    }
    
    answer=max(dp1[money.size()-1], dp2[money.size()]);
    return answer;
}
