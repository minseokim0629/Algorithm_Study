#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int L, C;
char pw[16], ans[16];

void dfs(int pos, int prev, int consonant, int vowel) {//자음, 모음(a,e,i,o,u)
	if (pos == L) {
		if (consonant >= 2 && vowel >= 1) {
			for (int i = 0; i < L; i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = prev + 1; i < C; i++) {
		ans[pos] = pw[i];
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
			dfs(pos + 1, i, consonant, vowel + 1);
		else
			dfs(pos + 1, i, consonant + 1, vowel);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> pw[i];
	}
	sort(pw, pw + C);
	dfs(0, -1, 0, 0);
	return 0;
}
