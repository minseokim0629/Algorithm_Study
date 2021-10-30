#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> numbers;
    
    for(int i=1; i<=sqrt(yellow); i++){
        if(yellow%i == 0) numbers.push_back({yellow/i, i});
    }
    
    for(int i=0; i<numbers.size(); i++){
        int fir=numbers[i].first;
        int sec=numbers[i].second;
        int sum = fir*2 + sec*2 + 4;
        if(brown==sum){
            answer.push_back(fir+2);
            answer.push_back(sec+2);
            break;
        }
    }
    return answer;
}
