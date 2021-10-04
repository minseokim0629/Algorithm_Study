#include <string>
#include <vector>
using namespace std;

int person1[5] = {1,2,3,4,5};
int person2[8] = {2,1,2,3,2,4,2,5};
int person3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result(3);
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==person1[i%5]) result[0]++;
        if(answers[i]==person2[i%8]) result[1]++;
        if(answers[i]==person3[i%10]) result[2]++;
    }

    int max_score = max(max(result[0], result[1]), result[2]);
     
    for(int i=0; i<3; i++){
        if(result[i]==max_score)
            answer.push_back(i+1);
    }
    return answer;
}
