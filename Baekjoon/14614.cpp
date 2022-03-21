#include<iostream>
#include<string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int a, b;
	int tmp;
	string c;
	cin >> a >> b;
	cin >> c;
	tmp = c[c.size() - 1] - '0';
	if (tmp%2) {
		cout << (a^b) << '\n';
	}
	else
	{
		cout << a<< '\n';
	}
	return 0;
}