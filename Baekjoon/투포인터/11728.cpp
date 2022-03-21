#include<iostream>
#include<vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int ptr1 = 0, ptr2 = 0;
	cin >> n >> m;
	vector<int> v1(n);
	vector<int> v2(m);
	vector<int> ans;

	for (auto &i : v1) {
		cin >> i;
	}
	for (auto&i : v2) {
		cin >> i;
	}

	while (1) {
		if (ptr1 == n && ptr2 == m)
			break;
		//ptr1이 n-1인 경우
		else if (ptr1 == n) {
			ans.push_back(v2[ptr2++]);
		}
		//pt2가 m-1인 경우
		else if (ptr2 == m) {
			ans.push_back(v1[ptr1++]);
		}
		//v1원소>v2원소
		else if (v1[ptr1] >= v2[ptr2]) {
			ans.push_back(v2[ptr2++]);
		}
		//v2원소>v1원소
		else if (v2[ptr2] > v1[ptr1]) {
			ans.push_back(v1[ptr1++]);
		}
	}

	for (auto &i : ans) {
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}
