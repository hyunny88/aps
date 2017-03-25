#include <stdio.h>
int arr[9][9];
int c1[9][9]; //row
int c2[9][9]; //col
int c3[9][9]; //box
bool checkAll() {
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			if (arr[j][i] == 0)
				return false;
		}
	}
	return true;
}

bool checkRow(int row, int val) {
	if (c1[row][val] == 1)
		return false;
	return true;
}
bool checkBox(int row, int val) {
	if (c1[row][val] == 1)
		return false;
	return true;
}
bool checkCol(int col, int val) {
	if (c1[val][col] == 1)
		return false;
	return true;
}
void findV(int j, int i) {
	if (checkAll()) {
		return;
	}
	for (int v = 1; v <= 9; v++) {
		if (!checkRow(j, v)) {
			continue;
		}
		if (!checkCol(i, v)) {
			continue;
		}
		if (!checkBox(j, i)) {
			continue;
		}
	}

}
int main() {
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			scanf("%d ", &arr[j][i]);
		}
	}
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			if (arr[j][i] == 0)
				findV(j, i);
		}
	}
	/*
	결과 출력
	*/
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			printf("%d ", arr[j][i]);
		}
		printf("%\n");
	}

	return 0;
}