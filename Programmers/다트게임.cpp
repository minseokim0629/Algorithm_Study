#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int prev=0, cur=0;
    
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9){
            prev = cur;
            if(dartResult[i+1] == '0'){
                cur = 10;
                i++;
            }
            else
                cur = dartResult[i] - '0';
        }
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if(dartResult[i] == 'D')
                cur = pow(cur, 2);
            else if(dartResult[i] == 'T')
                cur = pow(cur, 3);
            
            if(dartResult[i+1] == '*')
            {
                answer-=prev;
                prev*=2;
                cur*=2;
                answer+=prev;
                i++;
            }
            else if(dartResult[i+1] == '#')
            {
               cur*=-1;
               i++; 
            }
            answer+=cur;
        }
    }
    return answer;
}
