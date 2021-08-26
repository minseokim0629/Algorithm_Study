#include <vector>
#include <algorithm>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int currentNumber) {

	if (count >= 9) //일정횟수 이상 감
		return;

	if (currentNumber == number) {
		//현재수가 number와 같다면 작은횟수를 answer에 저장후 리턴
		answer = min(answer, count);
		return;
	}
	int tempNumber = 0;
	for (int i = 0; i + count < 9; i++) {
		//최대 N의 사용횟수는 9번
		tempNumber = tempNumber * 10 + N;

		dfs(N, number, count + 1 + i, currentNumber + tempNumber);
		dfs(N, number, count + 1 + i, currentNumber - tempNumber);
		dfs(N, number, count + 1 + i, currentNumber * tempNumber);
		dfs(N, number, count + 1 + i, currentNumber / tempNumber);
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	if (answer == 9)
		return -1;
	return answer;
}
