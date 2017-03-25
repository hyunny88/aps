#include <stdio.h>
int n;
int ir[100001];
int pr[100001];
int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &ir[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d ", &pr[i]);
	}

	/*
	입력검증
	
	for (int i = 0; i < n; i++) {
		printf("%d ", ir[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", pr[i]);
	}
	*/
	return 0;
}