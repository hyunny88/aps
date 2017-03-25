#include <stdio.h>
int N, M;
int s[1000001];



int find(int x) {
	if(x==s[x]){
		return x;
	}
	else {
		return s[x] = find(s[x]);
	}
}

void un(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		s[y] = x;
	}
}
int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i <= N; i++) {
		s[i] = i;//초기 node의 root는 자기자신
	}
	for (int m = 0; m < M; m++) {
		int op;
		int s1, s2;
		scanf("%d %d %d", &op, &s1, &s2);
		if (op == 0) { //union
			un(s1, s2);
		}
		else if (op == 1) { //find
			int x = find(s1);
			int y = find(s2);
			if (x == y) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}