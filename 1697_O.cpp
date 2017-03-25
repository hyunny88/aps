#include <stdio.h>
int N, K;

struct pos{
	int p;
	int cnt;
};
pos q[10000001];
int v[100001];
int head, tail;
int cnt;

int main() {
	scanf("%d %d", &N, &K);
	pos tt;
	tt.p = N;
	tt.cnt = 0;
	q[head++] = tt;
	v[tt.p] = 1;
	pos tmp;
	while (1) {
		tmp = q[tail++];
		if (tmp.p == K) {
			cnt = tmp.cnt;
			break;
		}
		if (tmp.p * 2 > 0 && tmp.p * 2 <= 100000 && v[tmp.p*2]==0) {
			pos t = { tmp.p * 2 ,tmp.cnt + 1 };
			q[head++] = t;
			v[t.p] = 1;
		}
		if (tmp.p + 1 >= 0 && tmp.p + 1 <= 100000 && v[tmp.p + 1] == 0) {
			pos t = { tmp.p + 1,tmp.cnt+1 };
			q[head++] = t;
			v[t.p] = 1;
		}
		if (tmp.p - 1 >= 0 && tmp.p-1 <=100000 && v[tmp.p - 1] == 0) {
			pos t = { tmp.p -1,tmp.cnt +1 };
			q[head++] = t;
			v[t.p] = 1;
		}
	
		
	}
	printf("%d\n", cnt);
	return 0;
}