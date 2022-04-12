#include <string>
#include <vector>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    //캐시크기가 0일 때 예외 처리
    if(cacheSize == 0)
        return 5 * cities.size();
    
    for(int i=0; i<cities.size(); i++){
        bool find=false;
        for(int j=0; j<cities[i].size(); j++){
            cities[i][j] = toupper(cities[i][j]);
        }
        for(int j=0; j<cache.size(); j++){
            if(cache[j] == cities[i]){
                find=true;
                cache.erase(cache.begin()+j);
                break;
            }
        }
        if(find){
            answer+=1;
        }
        else{
            answer+=5;
            if(cache.size()==cacheSize)
                cache.erase(cache.begin());
        }
        cache.push_back(cities[i]);
    }
    return answer;
}
