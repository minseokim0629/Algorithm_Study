#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> food;
    
    for(int i=0; i<scoville.size(); i++){
        food.push(scoville[i]);
    }
    
    while(food.top() < K){
        int fir = food.top();
        food.pop();
        int sec = food.top();
        food.pop();
        
        int tmp = fir + sec*2;

        if(food.size()==1 && tmp < K) return -1;
        else{
            food.push(tmp);
            answer++;
        }
    }
    return answer;
}
