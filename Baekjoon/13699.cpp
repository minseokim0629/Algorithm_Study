#include<iostream>
#include<vector>
using namespace std;

vector<long long> v;
void pre_cal(int n);
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	pre_cal(n);
	cout << v[n] << '\n';
	return 0;
}

void pre_cal(int n) {
	long long tmp;
	for (int i = 0; i <= 35; i++) {
		tmp = 0;
		if (i == 0)
			v.push_back(1);
		else {
			for (int j = 0; j < i; j++) {
				tmp += (v[j] * v[i - 1 - j]);
			}
			v.push_back(tmp);
		}
	}
}