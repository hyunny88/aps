#include <stdio.h>
int N, M;
int s[1000001];

int find(int x) {
	if (x == s[x]) {
		return x;
	}
	else {
		return s[x] = find(s[x]);
	}
}

void un(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		s[y] = x;
	}
}
int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 1; i <= N; i++) {
		s[i] = i;//초기 node의 root는 자기자신
	}
	for (int m = 0; m < M; m++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		un(tmp1, tmp2);
	}
	int result = 0;
	for (int i = 2; i <= N; i++) {
		if (find(1) == find(i)) {
			result++;
		}
	}
	printf("%d\n", result);
	return 0;
}