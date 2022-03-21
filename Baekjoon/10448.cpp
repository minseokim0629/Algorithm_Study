#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

void triangle_num() {
	int n = 1;
	while (n*(n + 1) / 2 <= 1000) {
		v.push_back(n*(n + 1) / 2);
		n++;
	}
}

bool three_triangle(int l) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (v[i] + v[j] + v[k] == l)
					return true;
			}
		}
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, k;
	cin >> t;
	triangle_num();
	for (int i = 0; i < t; i++) {
		cin >> k;
		cout << three_triangle(k) << '\n';
	}
	return 0;
}