#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check[10001];
vector<string> answer;

bool dfs(vector<vector<string>> tickets, string cur, int count){
    if(count==tickets.size())
        return true;

    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0]==cur && check[i]==false){
            check[i]=true;
            answer.push_back(tickets[i][1]);
            bool T = dfs(tickets, answer[answer.size()-1], count+1);
            if(T) return true;
            check[i]=false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    answer.push_back("ICN");
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 0);
    return answer;
}
