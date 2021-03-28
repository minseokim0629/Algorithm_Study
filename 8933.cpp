#include<iostream>
#include<map>
#include<string>
using namespace std;

struct Count {
	int A=0;
	int G=0;
	int C=0;
	int T=0;
};

long long Hash(Count c) {
	return c.A * 601 * 601 * 601 + c.G * 601 * 601 + c.C * 601 + c.T;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t, k;
	cin >> t;
	for(int i=0; i<t; i++){
		int j = 0, max = 0;
		map<long long, int> m;
		string s1;
		Count c;
		cin >> k;
		cin >> s1;
		for ( ; j < k; j++) {
			if (s1[j] == 'A')
				c.A++;
			else if (s1[j] == 'G')
				c.G++;
			else if (s1[j] == 'C')
				c.C++;
			else
				c.T++;
		}
		m[Hash(c)] = 1;
		for (; j < s1.size(); j++) {
			if (s1[j] == 'A')
				c.A++;
			else if (s1[j] == 'G')
				c.G++;
			else if (s1[j] == 'C')
				c.C++;
			else
				c.T++;
			if (s1[j-k] == 'A')
				c.A--;
			else if (s1[j-k] == 'G')
				c.G--;
			else if (s1[j-k] == 'C')
				c.C--;
			else
				c.T--;
			if (m.find(Hash(c)) == m.end())
				m[Hash(c)] = 1;
			else
				m[Hash(c)] ++;
		}
		for (map<long long, int> ::iterator it = m.begin(); it != m.end(); it++) {
			if (max < (*it).second)
				max = (*it).second;
		}
		cout << max << '\n';
	}
}