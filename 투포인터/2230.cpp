#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, ptr1 = 0, ptr2 = 1, M, diff = 2000000001;

	cin >> N >> M;
	vector<int> A(N);

	for (auto &i : A) {
		cin >> i;
	}

	sort(A.begin(), A.end());

	while (1) {
		if (ptr2 == N)
			break;
		if (A[ptr2] - A[ptr1] < M) {
			ptr2++;
			continue;
		}
		if (A[ptr2] - A[ptr1] == M)
		{
			diff = M;
			break;
		}
		diff = min(diff, A[ptr2] - A[ptr1]);
		ptr1++;
	}
	cout << diff << '\n';
	return 0;
}
