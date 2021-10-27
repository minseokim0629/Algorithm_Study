using namespace std;

long long gcd(int w, int h){
    long long mod;
    while(h!=0){
       mod = w%h;
       w = h;
       h = mod;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1; 
    long long tmp = (w+h)-gcd(w,h);
    answer = (long long)w*(long long)h - tmp;
    return answer;
}
