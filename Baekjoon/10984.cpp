#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, C;
	double G;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int total = 0;
		double avg = 0;
		for (int j = 0; j < N; j++) {
			cin >> C >> G;
			total += C;
			avg += (G*C);
		}
		avg = avg / total;
		cout << total << " " << avg << '\n';
	}
	return 0;
}