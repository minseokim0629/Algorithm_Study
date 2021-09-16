//팰린드롬 수
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "";
    bool palin = true;
    while (1)
    {
        palin = true;
        cin >> s;
        if (s == "0")
            break;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                palin = false;
                break;
            }
        }
        if (palin)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}