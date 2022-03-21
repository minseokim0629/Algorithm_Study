#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer =64;
int place[9][9];
int copy_place[9][9];
//방향 0: 북, 1: 동, 2 : 서, 3: 남
//(좌표 i, 좌표 j),(cctv번호, 방향)
vector<pair<pair<int, int>, pair<int, int>>> v;

void Up(int x, int y)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (copy_place[i][y] == 6)
			break;
		else if (copy_place[i][y] == 0)
			copy_place[i][y] = -1;
	}
}

void Right(int x, int y)
{
	for (int i = y + 1; i < M; i++)
	{
		if (copy_place[x][i] == 6)
			break;
		else if (copy_place[x][i] == 0)
			copy_place[x][i] = -1;
	}
}

void Down(int x, int y)
{
	for (int i = x + 1; i < N; i++)
	{
		if (copy_place[i][y] == 6)
			break;
		else if (copy_place[i][y] == 0)
			copy_place[i][y] = -1;
	}
}

void Left(int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (copy_place[x][i] == 6)
			break;
		else if (copy_place[x][i] == 0)
			copy_place[x][i] = -1;
	}
}

void Copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy_place[i][j] = place[i][j];
		}
	}
}

void Check_Area()
{
	Copy();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second.first == 1)
		{
			if (v[i].second.second == 0)
				Up(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 1)
				Right(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 2)
				Down(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 3)
				Left(v[i].first.first, v[i].first.second);
		}
		else if (v[i].second.first == 2)
		{
			if (v[i].second.second == 0 || v[i].second.second == 1)
			{
				Up(v[i].first.first, v[i].first.second);
				Down(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 2 || v[i].second.second == 3)
			{
				Left(v[i].first.first, v[i].first.second);
				Right(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3)
		{
			if (v[i].second.second == 0)
			{
				Up(v[i].first.first, v[i].first.second);
				Right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				Right(v[i].first.first, v[i].first.second);
				Down(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 2)
			{
				Down(v[i].first.first, v[i].first.second);
				Left(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 3)
			{
				Left(v[i].first.first, v[i].first.second);
				Up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4)
		{
			if (v[i].second.second == 0)
			{
				Left(v[i].first.first, v[i].first.second);
				Up(v[i].first.first, v[i].first.second);
				Right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				Up(v[i].first.first, v[i].first.second);
				Right(v[i].first.first, v[i].first.second);
				Down(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 2)
			{
				Right(v[i].first.first, v[i].first.second);
				Down(v[i].first.first, v[i].first.second);
				Left(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 3)
			{
				Down(v[i].first.first, v[i].first.second);
				Left(v[i].first.first, v[i].first.second);
				Up(v[i].first.first, v[i].first.second);
			}
		}
		if (v[i].second.first == 5)
		{
			Up(v[i].first.first, v[i].first.second);
			Right(v[i].first.first, v[i].first.second);
			Down(v[i].first.first, v[i].first.second);
			Left(v[i].first.first, v[i].first.second);
		}
	}
}

int Check_Zero()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copy_place[i][j] == 0)
				sum++;
		}
	}
	return sum;
}

void Set_Direction(int cnt)
{
	if (cnt == v.size())
	{
		Check_Area();
		answer = min(Check_Zero(), answer);
		return;
	}

	v[cnt].second.second = 0;
	Set_Direction(cnt + 1);

	v[cnt].second.second = 1;
	Set_Direction(cnt + 1);

	v[cnt].second.second = 2;
	Set_Direction(cnt + 1);

	v[cnt].second.second = 3;
	Set_Direction(cnt + 1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> place[i][j];
			if (place[i][j] >= 1 && place[i][j] <= 5)
				v.push_back({ {i, j}, {place[i][j], -1} });
		}
	}

	Set_Direction(0);
	cout << answer << '\n';
	return 0;
}
