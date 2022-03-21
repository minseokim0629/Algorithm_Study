#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, sum = 0, min = 2000000001;
	cin >> N;
	vector<int>v(N);
	vector<int>ans(2);
	for (auto &i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end());

	int ptr1 = 0, ptr2 = N - 1;

	while (ptr1 < ptr2) {
		sum = v[ptr1] + v[ptr2];
		if (min > abs(sum)) {//abs->절댓값 구하는법
			min = abs(sum);
			ans[0] = v[ptr1];
			ans[1] = v[ptr2];
			if (sum == 0) 
				break;
		}

		if (sum < 0)
			ptr1++;
		else
			ptr2--;
	}
	cout << ans[0] << " " << ans[1] << '\n';
	return 0;
}
