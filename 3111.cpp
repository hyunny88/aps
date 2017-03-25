#include <stdio.h>
char A[25];
char T[300001];

char LS[300001];
char RS[300001];

int ls_top;
int rs_top;

int left_point;
int right_point;
int A_idx;

int mylen(char *t) {
	for (int i = 0; i < 300001; i++) {
		if (t[i] == '\0')
			return i;
	}
}

void removeWord(char *T) {
	
}

int main() {
	scanf("%s %s", A, T);
	int T_len = mylen(T);
	int A_len = mylen(A);

	right_point = T_len - 1;
	while (1) {
		while (right_point - left_point!=1) {	//left
			if (T[left_point] == A[A_idx]) {
				A_idx++;
			}
			else
			{
				A_idx == 0;
			}
			LS[ls_top++] = T[left_point++];

			if (A_idx == A_len) {
				ls_top = ls_top - A_len;
				A_idx = 0;
				break;
			}
		}

		while (right_point - left_point != 1) {	//right
			if (T[right_point] == A[A_len - A_idx-1]) {
				A_idx++;
			}
			else
			{
				A_idx == 0;
			}
			RS[rs_top++] = T[right_point--];

			if (A_idx == A_len) {
				rs_top = rs_top - A_len;
				A_idx = 0;
				break;
			}
		}
		if (right_point - left_point == 1)
			break;
	}
	while (ls_top != 0) {
		RS[rs_top++] = LS[ls_top--];
	}
	while (rs_top != 0) {
		printf("%c", RS[rs_top--]);
	}
	printf("\n");
	
	return 0;
}