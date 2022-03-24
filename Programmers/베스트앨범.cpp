#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, int> music; //장르별 음악 재생 횟수 저장
    map <string, map<int, int>> music_list; //장르별 각각 idx와 재생 횟수 저장
    
    for(int i=0; i<genres.size(); i++){
        music[genres[i]] += plays[i];
        music_list[genres[i]][i] = plays[i];
    }
    
    while(music.size()>0){
        string genre="";
        int max=0;
        
        // 가장 많이 재생된 장르 찾기
        for(auto pair : music){
            if(max < pair.second)
            {
                max = pair.second;
                genre = pair.first;
            }
        }
        
        // 해당 장르 중 가장 많이 재생된 2곡 찾기
        for(int i=0; i<2; i++){
            int idx=-1, num=0; //인덱스, 재생 횟수
            for(auto pair : music_list[genre]){
                if(num < pair.second){
                    num = pair.second;
                    idx = pair.first;
                }
            }
            //노래가 2곡 미만이면 탈출
            if(idx == -1) break;
            answer.push_back(idx);
            music_list[genre].erase(idx);
        }
        music.erase(genre);
    }
    
    return answer; 
}
