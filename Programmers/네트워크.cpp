#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &computers, int cur){
    //이미 순회한 노드라면 리턴(재귀함수 탈출조건)
    if(!computers[cur][cur]) 
        return false;
    computers[cur][cur]=0;
    for(int i=0; i<computers[cur].size(); i++){
        if(computers[cur][i])
            dfs(computers, i);
    }
    return true;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<computers.size(); i++){
        if(computers[i][i] && dfs(computers, i)) answer++;
    }
    return answer;
}
