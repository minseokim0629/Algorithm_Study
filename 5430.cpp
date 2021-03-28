#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s, s2, tmp="";
		deque<int> dq;
		bool print = true;
		bool reverse = false;//뒤집어있지 않다면 false
		cin >> s;
		cin >> n;
		cin >> s2;
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] == '[')
				continue;
			else if ((s2[i] >= '0'&&s2[i] <= '9'))
				tmp += s2[i];
			else if (s2[i] == ',' || s2[i] == ']') {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				reverse = !reverse;
			}
			else {
				if (dq.empty()) {
					print = false;
					break;
				}
				else
				{
					if (!reverse)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		if (print) {
			cout << "[";
			if (!reverse) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			cout << "]" << '\n';
		}
		else {
			cout << "error" << '\n';
		}
	}
	return 0;
}