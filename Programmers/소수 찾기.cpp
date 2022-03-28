#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int a){
    if(a<2) return false;
    
    for(int i=2; i<=sqrt(a); i++){
        if(a%i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    vector<int> tmp;
    for(int i=0; i<numbers.size(); i++){
        num.push_back(numbers[i]-'0');
    }

    sort(num.begin(), num.end());
    
    do{
        for(int i=0; i<num.size(); i++){
            int a = 0;
            for(int j=0; j<=i; j++){
                a = a*10 + num[j];
                tmp.push_back(a);
            }
        }
    }
    while(next_permutation(num.begin(), num.end()));
    
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    for(int i =0; i<tmp.size(); i++){
        if(check(tmp[i]))
            answer++;
    }
    
    return answer;
}
