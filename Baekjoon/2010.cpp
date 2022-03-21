#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, total = 0, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		total += x - 1;
	}
	cout << total+1 << '\n';
	return 0;
}