#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

int score[7]={6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int unknown=0;
    int same=0;
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]==0){
            unknown++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
            if(lottos[i]==win_nums[j]) {
                same++;
                break;
            }
        }
    }
    answer.push_back(score[same+unknown]); //최고 순위
    answer.push_back(score[same]); //최저 순위
    return answer;
}
