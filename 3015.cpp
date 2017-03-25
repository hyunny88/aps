#include <stdio.h>
int N;
int stack[500001];
int top;
int main() {
	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d ", &tmp);
		if (top == 0) {
			stack[top++] = tmp;
		}
		else if (stack[top] < tmp) {

		}
		
	}
	return 0;
}