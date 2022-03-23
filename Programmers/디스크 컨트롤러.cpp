#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end()); //요청시점으로 정렬
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //소요시간 순 정렬
    int time=0, idx=0;
    
    
    while(idx<jobs.size() || !pq.empty()){
        if(idx<jobs.size() && jobs[idx][0] <=time){
            pq.push(jobs[idx++]);
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top()[1];
            answer += (time - pq.top()[0]);
            pq.pop();
        }
        else
            time = jobs[idx][0];
    }
    return answer/jobs.size();
}
