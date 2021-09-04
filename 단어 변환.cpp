#include <string>
#include <vector>

using namespace std;

int answer = 51;
bool check[51];

void dfs(string begin, string target, vector<string>& words, int count){
    if(begin==target){
        answer=min(answer, count);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        int diff=0;
        for(int j=0; j<words[i].size(); j++){
            if(begin[j]!=words[i][j])
                diff++;
            if(diff==2) break;
        }
        if(diff==1 && check[i]==false){
            check[i]=true;
            dfs(words[i], target, words, count+1);
            check[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer==51) answer=0;
    return answer;
}
