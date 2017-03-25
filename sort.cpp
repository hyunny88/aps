#include <stdio.h>

int arr[] = {5,3,2,9,7,4,1};
int b[7];
void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) b[k++] = arr[i++];
		else b[k++] = arr[j++];
	}
	while (i <=mid) {
		b[k++] = arr[i++];
	}
	while (j <=end) {
		b[k++] = arr[j++];
	}
	for (int i = start; i <= end; i++) {
		arr[i] = b[i - start];
	}
}

void mergeSort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid+1,end);
	merge(start, end);
}
int main() {
	mergeSort(0,6);
	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}