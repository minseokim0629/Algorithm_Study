#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int num){
    if(num==1) return false;
    if(num==2) return true;
    if(num%2 == 0) return false;
    for(int i=3; i<=sqrt(num); i++){
        if(num%i == 0) return false;
    }
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                int sum = nums[i]+nums[j]+nums[k];
                if(IsPrime(sum)) answer++;
            }
        }
    }
    return answer;
}
