#include <stdio.h>
int Y, X;

int src[51][51];
int tar[51][51];

bool sameAll() {
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (src[y][x] != tar[y][x])
				return false;
		}
	}
	return true;
}
void flatBoard(int y, int x) {
	for (int j = y; j < y + 3 && j < Y; j++) {
		for (int i = x; i < x + 3 && i < X; i++) {
			if (tar[j][i] == 1) {
				tar[j][i] = 0;
			}
			else if(tar[j][i]==0){
				tar[j][i] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &Y, &X);
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%1d", &src[y][x]);
		}
	}
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%1d", &tar[y][x]);
		}
	}
	int result = 0;
	for (int y = 0; y < Y-2; y++) {
		for (int x = 0; x < X-2; x++) {
			if (src[y][x] != tar[y][x]) {
				flatBoard(y, x);
				result++;
			}
		}
	}
	if (sameAll()) {
		printf("%d\n", result);
	}
	else {
		printf("-1");
	}
	/*
	입력검증
	
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			printf("%d", src[y][x]);
		}
		printf("\n");
	}
	
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			printf("%d", tar[y][x]);
		}
		printf("\n");
	}
	*/
	return 0;
}