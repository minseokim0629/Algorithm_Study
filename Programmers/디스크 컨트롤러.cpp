#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, idx=0, time=0;
    sort(jobs.begin(), jobs.end());
    //오름차순 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(idx<jobs.size()||!pq.empty()){
        if(idx<jobs.size() && time>=jobs[idx][0]){
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            //동일 시간 체크 위해
            continue;
        }
        
        if(!pq.empty()){
            time+=pq.top().first;
            answer+=(time-pq.top().second);
            pq.pop();
        }
        else
            time=jobs[idx][0];
    }
    answer/=jobs.size();
    return answer;
}
