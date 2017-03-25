#include <stdio.h>
char str[1000001];
char boom[37];
char stack[1000001];
int top;
int str_idx;
int mylen(char *t) {
	for (int i = 0; i < 300001; i++) {
		if (t[i] == '\0')
			return i;
	}
}

bool checkBoom(int boom_len) {
	for (int i = 0; i < boom_len; i++) {
		if (stack[top - 1 - i] != boom[boom_len - 1 - i])
			return false;
	}
	return true;
}

void removeBoom(int boom_len) {
	for (int i = 0; i < boom_len; i++) {
		stack[--top] = '\0';
	}
}

int main() {
	scanf("%s", str);
	scanf("%s", boom);
	int str_len = mylen(str);
	int boom_len = mylen(boom);

	while (str_idx<str_len) {
		stack[top++] = str[str_idx++];
		if (top >= boom_len) {
			if (checkBoom(boom_len)) {
				removeBoom(boom_len);
			}
		}
	}
	if (top == 0) {
		printf("FRULA\n");
	}
	else {
		printf("%s\n", stack);
	}
	return 0;
}