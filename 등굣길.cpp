#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //모두 1로 초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=1;
        }
    }
    
    for(int i=0; i<puddles.size(); i++){
       int x = puddles[i][0];
       int y = puddles[i][1];
       if(x==1){
           for(int j=y; j<=n; j++){
               dp[j][1]=0;
           }
       }
       if(y==1){
           for(int j=x; j<=m; j++){
               dp[1][j]=0;
           }
       }
       dp[y][x]=0;
   }
    
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
           if(dp[i][j]==0)
               continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    answer=dp[n][m]%1000000007;
    return answer;
}
