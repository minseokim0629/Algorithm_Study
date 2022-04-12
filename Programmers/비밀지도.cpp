#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp;
    
    for(int i=0; i<n; i++){
        int num = arr1[i] | arr2[i];
        tmp="";
        for(int j=0; j<n; j++){
            if(num%2)
                tmp = '#' + tmp;
            else
                tmp = ' ' + tmp;
            num = num >> 1;
        }
        answer.push_back(tmp);
    }
    
    return answer;
}
