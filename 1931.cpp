//회의실 배정
#include <stdio.h>
int N;
struct meet {
	int start;
	int end;
};

meet q[100000];

void swap(int i, int j) {
	meet tmp = q[j];
	q[j] = q[i];
	q[i] = tmp;
}
/*
sort?
*/
void sort() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (q[i].end == q[j].end) {
				if (q[i].start < q[j].start) {
					swap(i, j);
				}
			}
			else if(q[i].end < q[j].end){
				swap(i, j);
			}
		}
	}
}

void quickSort(int left, int right) {
	int i = left, j = right;
	meet tmp;
	int pivot = q[(left + right) / 2].end;

	while (q[j].end > pivot)
		j--;

	if (i <= j) {
		tmp = q[i];
		q[i] = q[j];
		q[j] = tmp;
		i++;
		j--;
	}

	/* recursion */
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d %d ", &q[n].start, &q[n].end);
	}
	quickSort(0,N-1);
	int now = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (now <= q[i].start) {
			now = q[i].end;
			ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}