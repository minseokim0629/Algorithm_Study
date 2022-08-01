#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int city[51][51];
vector<pair<int, int>> house, chicken;
vector<pair<int, int>> v; //선택된 치킨집
int answer=100000001, N, M;
void chicken_select(int idx, int cnt);
int cal_distance();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back({ i, j });
			else if (city[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	chicken_select(0, 0);
	cout << answer << '\n';
	return 0;
}

void chicken_select(int idx, int cnt) {
	if (cnt == M) {
		answer = min(answer, cal_distance());
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		v.push_back(chicken[i]);
		chicken_select(i+1, cnt + 1);
		v.pop_back();
	}
}

int cal_distance() {
	int sum = 0;

	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		int d = 100000001;
		for (int j = 0; j < v.size(); j++) {
			int dx = v[j].first;
			int dy = v[j].second;
			int dist = abs(dx - x) + abs(dy - y);
			d = min(d, dist);
		}
		sum += d;
	}
	return sum;
}
