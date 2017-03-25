#include <stdio.h>
int T, N;

int go(int sum, int goal) {
	if (sum > goal) return 0;	//불가능
	if (sum == goal) return 1;	//정답
	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(sum + i, goal);	//다음
	}
	return now;
}
int main() {
	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d ", &N);
		int count = 0;
		int sum = 0;
		int goal = N;
		printf("%d\n", go(0, goal));
	}
	return 0;
}