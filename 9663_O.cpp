#include <stdio.h>
int N;
int c[16][16];
int check_row[40];
int check_dig1[40];
int check_dig2[40];
bool check(int j, int i) {
	if (check_row[i] == 1)
		return false;
	if (check_dig1[j + i] == 1)
		return false;
	if (check_dig2[j - i + N] == 1)
		return false;
	return true;
}
int brute_force(int j) {
	if (j == N) {
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < N; col++) {
		if (check(j, col)) {
			
			c[j][col] = 1;
			check_row[col] = 1;
			check_dig1[j + col] = 1;
			check_dig2[j - col + N] = 1;
			
			cnt += brute_force(j + 1);

			check_row[col] = 0;
			check_dig1[j + col] = 0;
			check_dig2[j - col + N] = 0;
			c[j][col] = 0;

		}
	}
	return cnt;
}

int main() {
	scanf("%d", &N);
	printf("%d\n", brute_force(0));
	return 0;
}