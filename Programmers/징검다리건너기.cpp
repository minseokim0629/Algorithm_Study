#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(int mid, vector<int> stones, int k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid < 0)
        {
            cnt++;
            if (cnt >= k)
                return false;
        }
        else
            cnt = 0;
    }
    return true;
}
int solution(vector<int> stones, int k)
{
    int answer = 0;
    int start = 0;
    //o(n)
    int end = *max_element(stones.begin(), stones.end());
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (binary_search(mid, stones, k))
        {
            answer = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return answer;
}
