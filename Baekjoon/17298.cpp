#include<iostream>
#include<stack>
using namespace std;

int res[1000001] = {};

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, cur;
	stack<pair<int, int>> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (!i)
			s.push({ i, x });
		else {
			cur = s.top().second;
			if (cur < x) {
				while (!s.empty()) {
					auto j = s.top();
					if (j.second < x) {
						res[j.first] = x;
						s.pop();
					}
					else
						break;
				}
			}
			s.push({ i, x });
		}
	}
	while (!s.empty()) {
		res[s.top().first] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << '\n';
	return 0;
}