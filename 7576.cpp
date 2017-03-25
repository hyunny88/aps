#include <stdio.h>
int M, N;
int arr[1001][1001];
struct pos {
	int y;
	int x;
	int cnt;
};

pos q[1000000];
int head;
int tail;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	scanf("%d %d ", &M, &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d ", &arr[y][x]);
			if (arr[y][x] == 1) {
				pos tmp;
				tmp.y = y;
				tmp.x = x;
				tmp.cnt = 0;
				q[head++] = tmp;
			}
		}
	}
	int result = 0;
	while (head != tail) {
		pos cur = q[tail++];
		if (result < cur.cnt) {
			result = cur.cnt;
		}
		for (int d = 0; d < 4; d++) {
			if (cur.y + dy[d] < N && cur.x + dx[d] < M &&cur.y + dy[d] >= 0 && cur.x + dx[d] >= 0 && arr[cur.y+dy[d]][cur.x+dx[d]] == 0) {
				pos tmp;
				tmp.y = cur.y + dy[d];
				tmp.x = cur.x + dx[d];
				tmp.cnt = cur.cnt +1;
				q[head++] = tmp;
				arr[cur.y + dy[d]][cur.x + dx[d]] = 1;
			}
		}
	}
	printf("%d", result);

	return 0;
}
