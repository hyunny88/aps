#include <stdio.h>
/*
5 0
-7 -3 -2 5 8

int N, S;
int arr[21];
int count;
void find(int index, int sum) {
	if (index == N) {
		if (sum == S) {
			count++;
		}
		return;
	}
	find(index + 1, sum + arr[index]);
	find(index + 1, sum );
}
int main() {
	scanf("%d %d", &N, &S);
	
	for (int n = 0; n < N; n++) {
		scanf("%d ", &arr[n]);
	}
	int index = 0;
	int sum = 0;
	find(index, sum);
	if (S == 0) count -= 1;
	printf("%d\n", count);
	return 0;
}

*/

int arr[21];
int N, S;
int main() {
	scanf("%d %d", &N, &S);

	for (int n = 0; n < N; n++) {
		scanf("%d ", &arr[n]);
	}
	int result = 0;
	for (int i = 1; i<(1 << N); i++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			if (i&(1 << k)) {
				sum += arr[k];
			}
		}
		if (sum == S) {
			result += 1;
		}
	}
	printf("%d\n", result);
	return 0;
}