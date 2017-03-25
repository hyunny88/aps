//µ¿Àü0
#include <stdio.h>
int N, K;
int type[10];
int main() {
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		scanf("%d ", &type[n]);
	}
	int ans = 0;
	for (int n = N - 1; n >= 0; n--) {
		int n1 = K / type[n];
		K -= n1*type[n];
		//int n2 = K % type[n];
		ans += n1;
	}
	printf("%d", ans);
	return 0;
}