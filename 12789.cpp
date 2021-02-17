#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	stack<int> s;
	vector<int> v;
	int N, x, count = 1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

		while(v.size()!=0){

			if (count == *(v.begin()))
			{
				count++;
				v.erase(v.begin());
			}
			else if (!s.empty() && s.top() == count) {
				s.pop();
				count++;
			}
			else {
				s.push(*(v.begin()));
				v.erase(v.begin());
			}
			
		}
		
		while(!s.empty()){

			if (count == s.top()) {
				count++;
				s.pop();
			}
			else
			{
				cout << "Sad" << '\n';
				return 0;
			}
		}

		cout << "Nice" << '\n';
	return 0;
}
