#include<iostream>
#include<vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &i : v) {
		cin >> i;
	}
	int sum = v[0], ans = 0;
	int ptr1 = 0, ptr2 = 0;
	while (1) {
		if (sum == m)
			ans++;
		
		//탈출 조건
		if (ptr1 == n - 1 && ptr2 == n - 1)
			break;
		
		//ptr1과 ptr2가 같은 위치에 있는 경우
		if (ptr1 == ptr2) {
			sum += v[++ptr2];
			continue;
		}

		//ptr2가 맨 끝에 있는 경우
		if (ptr2 == n - 1) {
			sum -= v[ptr1++];
			continue;
		}

		//sum==m인 경우도 처리해줘야 하므로
		if (sum <= m) {
			sum += v[++ptr2];
			continue;
		}

		if (sum > m) {
			sum -= v[ptr1++];
			continue;
		}
	}
	cout << ans << '\n';
	return 0;
}
