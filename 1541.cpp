#include <stdio.h>
char arr[51];

int mylen(char *ar) {
	int result = 0;
	while (ar[result] != '\0')
		result++;
	return result;
}
int main() {
	scanf("%s", &arr);
	int n = mylen(arr);
	int min = 0;
	int value = 0;
	int pos = 0;
	/*
	parsing �� ���� eval �ʿ�
	*/
	for (int i = 0; i < n; i++) {
		if (arr[i] == '-') {

		}
		else if (arr[i] == '+') {

		}
		else {
			
		}
	}
	return 0;
}