#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, x1, y1, x2, y2, cx, cy, r, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			if ((cx - x1)*(cx - x1) + (cy - y1)*(cy - y1)>r*r) {
				if ((cx - x2)*(cx - x2) + (cy - y2)*(cy - y2) < r*r)
					cnt++;
			}
			else {
				if ((cx - x1)*(cx - x1) + (cy - y1)*(cy - y1) < r*r) {
					if ((cx - x2)*(cx - x2) + (cy - y2)*(cy - y2) > r*r)
						cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
