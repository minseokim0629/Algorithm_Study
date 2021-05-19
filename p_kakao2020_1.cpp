#include <string>
using namespace std;

int solution(string s) {
	int answer = s.size();
	for (int i = 1; i <= s.size() / 2; i++) {
		string tmp = "", result = "";
		int cnt = 1;
		tmp = s.substr(0, i);
		for (int j = i; j < s.size(); j += i) {
			if (tmp == s.substr(j, i))
				cnt++;
			else {
				if (cnt > 1)
					result += to_string(cnt);
				result += tmp;
				tmp = s.substr(j, i);
				cnt = 1;
			}
		}
		if (cnt > 1)
			result += to_string(cnt);
		result += tmp;
		if (answer > result.size())
			answer = result.size();
	}

	return answer;
}