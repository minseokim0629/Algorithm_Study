#include<iostream>
#include<vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	int n, m, tmp;
	int low = 0, high = 0, total = 0, count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	while (low <= high && high < n) {
		if (total < m) {
			total += v[high];
			high++;
		}
		if (total == m) {
			count += 1;
			low = high - 1;
			total = v[low];
		}
		if(total>m) {
			total -= v[high-1];
			low += 1;
			if (low > high) {
				high = low;
			}
		}
	}
	cout << count << '\n';
	return 0;
}