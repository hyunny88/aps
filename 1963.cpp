#include <stdio.h>
int T;
int src, tar;
struct pwd {
	int num;
	int cnt;
};

bool isPrime(int n) {
	for (int i = 1000; i < n; i++) {
		if (n / i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		pwd q[5000];
		int head = 0;
		int tail = 0;
		int result = 0;
		scanf("%d %d ", &src, &tar);

		pwd tmp = { src,0 };
		q[head++] = tmp;
		
		while (head != tail) {
			pwd tt = q[tail++];
			if (tt.num == tar) {
				result = tt.cnt;
				break;
			}


		}

		printf("%d\n", result);
	}
	return 0;
}