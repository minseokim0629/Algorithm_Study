#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (auto &i : v) {
		cin >> i;
	}
	int ptr1 = 0, ptr2 = 0;
	int sum = (v[0] == 1), ans=1000001;

	while (1) {
		if (sum >= K)
			ans = min(ans, ptr2 - ptr1 + 1);

		//탈출 조건
		if (ptr1 == N - 1 && ptr2 == N - 1)
			break;

		//ptr1과 ptr2가 같은 위치
		if (ptr1 == ptr2 ) {
			sum += (v[++ptr2] == 1);
			continue;
		}
		//ptr2가 끝에 있는 경우
		if (ptr2 == N - 1) {
			sum -= (v[ptr1++] == 1);
			continue;
		}

		if (sum < K) {
			sum += (v[++ptr2] == 1);
			continue;
		}

		if (sum>=K) {
			sum -= (v[ptr1++] == 1);
			continue;
		}
	}
	cout << (ans == 1000001 ? -1 : ans) << '\n';
	return 0;
}
