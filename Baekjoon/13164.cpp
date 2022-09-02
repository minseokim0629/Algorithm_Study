#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, x;
	int price = 0;
	vector<int> v;
	vector<int> diff;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		diff.push_back(v[i + 1] - v[i]);
	}
	sort(diff.begin(), diff.end());
	for (int i = 0; i < diff.size() - (K - 1); i++) {
		price += diff[i];
	}
	cout << price << '\n';
	return 0;
}
