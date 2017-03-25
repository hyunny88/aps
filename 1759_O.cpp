#include <stdio.h>
int L, C;
char al[16];
char password[16];

void swap(int i, int j) {
	char tmp = al[i];
	al[i] = al[j];
	al[j] = tmp;
}
void al_sort() {
	for (int i = 0; i < C-1; i++) {
		for (int j = i; j < C; j++) {
			if (al[i] > al[j]) {
				swap(i, j);
			}
		}
	}
}

bool check(char password[]) {
	int mo = 0;
	int ja = 0;
	for(int i=0;i<L;i++){
		if (password[i] == 'a' ||
			password[i] == 'i' ||
			password[i] == 'e' ||
			password[i] == 'o' ||
			password[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	return mo >= 1 && ja >= 2;
}
int myLen(char *str) {
	for (int i = 0; i <= 16; i++) {
		if (str[i] == '\0') {
			return i;
		}
	}
}
void concat(char *pwd, char t) {
	for (int i = 0; i <=16; i++) {
		if (pwd[i] == '\0') {
			pwd[i] = t;
			pwd[i + 1] = '\0';
			return;
		}
		else {
			pwd[i] = pwd[i];
		}
	}
}

void remove_last(char *pwd) {
	for (int i = 0; i <= 16; i++) {
		if (pwd[i] == '\0') {
			pwd[i - 1] = '\0';
			return;
		}
	}
}
void go(int len_L, char possible[], char pwd[], int index) {
	if (myLen(pwd) == len_L) {
		if (check(pwd)) {
			printf("%s\n", pwd);
		}
		return;
	}
	if (index >= myLen(possible)) return;
	concat(pwd, possible[index]);
	go(len_L, possible, pwd, index + 1);
	remove_last(pwd);
	go(len_L, possible, pwd, index + 1);
}
int main() {
	scanf("%d %d ", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf("%c ", &al[i]);
	}
	al_sort();
	go(L, al, password, 0);
	return 0;
}