#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int>p2)
{
	return p1.second < p2.second;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> v;//hi, ai
	int n, tmp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back({ tmp, -1 });
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v[i].second = tmp;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		sum += v[i].first + i * v[i].second;
	}

	cout << sum << '\n';
	return 0;
}
