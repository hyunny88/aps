#include <stdio.h>
int N;
int arr[1000];
void swap(int i, int j) {
	int tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}
void quickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	
	while (arr[j] > pivot)
	j--;

	if (i <= j) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}

	/* recursion */
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
void sort() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[i] < arr[j]) {
				swap(i, j);
			}
		}
	}
}
int main() {
	scanf("%d ", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d ", &arr[n]);
	}
	quickSort(0,N-1);
	int ans = 0;
	int sum = 0;
	for(int i=0;i<N;i++){
		sum += arr[i];
		ans += sum;
	}
	printf("%d", ans);
	return 0;
}