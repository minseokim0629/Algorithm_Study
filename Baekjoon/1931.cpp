#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, start, end;
	int cur = 0, cnt = 1;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end(), cmp);
	cur = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (cur <= v[i].first)
		{
			cur = v[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
