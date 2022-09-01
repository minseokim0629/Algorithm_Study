#include<iostream>
using namespace std;

int N, K;
int cnt = 0, total = 0;

void water() {
	int tmp = N;
	while (tmp > 0) {
		//나머지가 있으면 합쳐지지 못하고 남는 물병이 있다는 뜻
		if (tmp % 2) cnt++;
		tmp /= 2;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	while (1) {
		cnt = 0;
		water();
		if (cnt <= K) break;
		total++;
		N++;
	}
	cout << total << '\n';
	return 0;
}
