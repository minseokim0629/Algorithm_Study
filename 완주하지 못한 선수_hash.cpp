#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> tmp; //key, value
    
    for(string name : participant)
        tmp[name]++;
    
    for(string name : completion)
        tmp[name]--;
    
    for(auto pair : tmp){
        if(pair.second > 0)
        {
            answer = pair.first;
            break;
        }
    }
    return answer;
}
