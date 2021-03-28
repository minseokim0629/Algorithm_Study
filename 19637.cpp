#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> v1;
vector<int> v2;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int high, fight;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s >> high;
		v1.push_back(s);
		v2.push_back(high);
	}
	for (int i = 0; i < m; i++) {
		cin >> fight;
		cout << v1[lower_bound(v2.begin(), v2.end(), fight)-v2.begin()] << '\n';
	}

	return 0;
}