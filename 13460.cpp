#include <stdio.h>
int Y, X;
char arr[11][11];
int dy[4] = { 0,0,1,-1 }; //µ¿¼­³²ºÏ
int dx[4] = { 1,-1,0,0 };
int end_y, end_x;

struct pos {
	int b_x;
	int b_y;
	int r_x;
	int r_y;
	int cnt;
};

pos q[100000];
int head;
int tail;

int bfs() {
	while (head != tail) {
		pos tmp = q[head++];
		if (tmp.cnt >= 10)
			return -1;
		for (int d = 0; d < 4; d++) {
			int n_b_x = tmp.b_x + dx[d];
			int n_b_y = tmp.b_y + dy[d];
			int n_r_x = tmp.r_x + dx[d];
			int n_r_y = tmp.r_y + dy[d];
			int n_cnt = tmp.cnt + 1;

			if (n_b_x != end_x && n_b_y != end_y) {

			}
			if (n_r_y == end_y && n_r_y == end_y) {
				return n_cnt;
			}
		}
	}

}

int main() {
	scanf("%d %d ", &Y, &X);
	pos init;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%c", &arr[y][x]);
			if (arr[y][x] == 'B') {
				init.b_x = x;
				init.b_y = y;

			}
			else if(arr[y][x] == 'R') {
				init.r_x = x;
				init.r_y = y;
			}
			else if (arr[y][x] == 'O') {
				end_y = y;
				end_x = x;
			}
		}
		char tmp;
		scanf("%c",&tmp);
	}
	init.cnt = 0;
	q[0] = init;
	printf("%d\n", bfs());
	/*
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			printf("%c", arr[y][x]);
		}
		printf("\n");
	}
	*/
	return 0;
}
