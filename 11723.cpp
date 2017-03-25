#include <stdio.h>
int M;

int main() {
	scanf("%d", &M);
	int S = 0;
	for (int i = 0; i < M; i++) {
		char oper[10];
		int val;
		scanf("%s %d", oper, &val);
		val--;
		if (oper[0] == 'a' && oper[1] == 'd') {
			S = S | (1 << val);
		}
		else if (oper[0] == 'r') {
			S = S & ~(1 << val);
		}
		else if (oper[0] == 'c') {
			printf("%d\n", ( S&(1 << val)) > 0  ? 1:0);
		}
		else if (oper[0] == 't') {
			S = S ^(1 << val);
		}
		else if (oper[0] == 'a' && oper[1] == 'l') {
			S = (1 << 20)-1;
		}
		else if (oper[0] == 'e') {
			S = 0;
		}
	}
	return 0;
}