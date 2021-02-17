#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	deque<int> d;
	int x, n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (s == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (s == "pop_front") {
			if (d.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size")
			cout << d.size() << '\n';
		else if (s == "empty")
		{
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front")
		{
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		else if (s == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}
	return 0;
}
