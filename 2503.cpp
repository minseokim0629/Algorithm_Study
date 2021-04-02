#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<pair<string, pair<int, int>>> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, tmp;
	int n, a, b;
	int strike = 0, ball = 0;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cin >> a >> b;
		v.push_back({ s, {a,b} });
	}
	for (int i = 123; i <= 987; i++) {
		int right = 0;
		tmp = to_string(i);
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			continue;
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2])
			continue;
		for (int j = 0; j < v.size(); j++) {
			strike = 0;
			ball = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (tmp[k] == v[j].first[l])
					{
						if (k == l)
							strike++;
						else
							ball++;
					}
				}
			}
			if (strike == v[j].second.first&&ball == v[j].second.second)
				right++;
		}
		if (n == right)
			count++;
	}
	cout << count << '\n';
	return 0;
}