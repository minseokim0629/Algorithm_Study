#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	string p, X;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> p >> N >> X;
		deque<int> dq;
		string tmp = "";
		bool reverse = false;
		bool error = false;

		for (int j = 0; j < X.size(); j++) {
			if (X[j] >= '0' && X[j] <= '9')
				tmp += X[j];
			else if (X[j] == ',' || X[j] == ']') {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
		}

		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R')
				reverse = !reverse;
			else if (p[j] == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				if (reverse)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << "[";
			if (reverse) {
				while (!dq.empty()) {
					if (dq.size() == 1)
						cout << dq.back();
					else
						cout << dq.back() << ",";
					dq.pop_back();
				}
			}
			else {
				while (!dq.empty()) {
					if (dq.size() == 1)
						cout << dq.front();
					else
						cout << dq.front() << ",";
					dq.pop_front();
				}
			}
			cout << "]" << '\n';
		}
	}
	return 0;

}
