#include <string>
#include <vector>

using namespace std;

int answer = 0;

bool dfs(vector<vector<int>>& computers, int n){
    if(!computers[n][n]) return false;
    computers[n][n]=0;
    
    for(int i=0; i<computers[n].size(); i++){
        if(computers[n][i])
            dfs(computers,i);
    }
    return true;
}
int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<computers.size(); i++){
        if(computers[i][i] && dfs(computers, i)) answer++;
    }
    return answer;
}
