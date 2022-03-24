#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue <int, vector<int>, greater<int>> pq_min;
    priority_queue <int, vector<int>, less<int>> pq_max;
    int cnt=0;
    
    for(int i=0; i<operations.size(); i++){
      // 인덱스 0에서 1개만큼 문자열을 자르라는 의미
        string oper = operations[i].substr(0, 1);
      // 두번째 인자가 없으면 해당 인덱스에서 끝까지 자르라는 의미
        int num = stoi(operations[i].substr(2));
        
        if(cnt==0){
            while(!pq_min.empty())
            {
                pq_min.pop();
            }
            while(!pq_max.empty())
            {
                pq_max.pop();
            }
        }
        
        if(oper== "I"){
            pq_min.push(num);
            pq_max.push(num);
            cnt++;
        }
        else{
            if(num == 1){ // 최댓값 삭제
                if(!pq_max.empty())
                {
                    pq_max.pop();
                    cnt--;
                }
            }
            else{
                if(!pq_min.empty()){
                    pq_min.pop();
                    cnt--;
                }
            }
        }
    }
    
    if(cnt==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }
    return answer;
}
