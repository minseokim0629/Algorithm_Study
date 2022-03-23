#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> fashion;
    
    for(int i=0; i<clothes.size(); i++)
        fashion[clothes[i][1]] ++;

    
    for(auto pair : fashion){
        answer *= (pair.second + 1);
    }
    return answer-1;
}
