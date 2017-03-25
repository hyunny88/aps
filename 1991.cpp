//트리순회
#include <stdio.h>

int N;
char arr[100];
int pre[100];
int in[100];
int post[100];

void preorder(int idx) {
	if (pre[idx] == 0 && arr[idx] !='\0') {
		pre[idx] = 1;//root
		printf("%c", arr[idx]);	
		if (pre[idx * 2] == 0 && arr[idx * 2] != '\0') {
			preorder(idx * 2);
		}
		if (pre[idx * 2 + 1] == 0 && arr[idx * 2 + 1] != '\0') {
			preorder(idx * 2 + 1);
		}
	}
}
void inorder(int idx) {
	if (in[idx * 2] == 0 && arr[idx * 2] != '\0') {
		inorder(idx * 2);//왼쪽
	}
	if (in[idx] == 0) {
		printf("%c", arr[idx]);
		in[idx] = 1;
	}
	if (in[idx * 2+1] == 0 && arr[idx * 2+1] != '\0') {
		inorder(idx * 2+1);//오른쪽
	}
}
void postorder(int idx) {
	if (post[idx * 2] == 0 && arr[idx * 2] != '\0') {
		postorder(idx * 2);//왼쪽
	}
	if (post[idx * 2 + 1] == 0 && arr[idx * 2 + 1] != '\0') {
		postorder(idx * 2 + 1);//오른쪽
	}
	if (post[idx] == 0) {
		printf("%c", arr[idx]);
		post[idx] = 1;
	}
}

int findRoot(char c) {
	for (int i = 1; i < 100; i++) {
		if (arr[i] == c) {
			return i;
		}
	}
}
int main() {
	scanf("%d ", &N);
	int idx=1;
	for (int n = 0; n < N; n++) {
		char root, left, right;
		scanf("%c %c %c ",&root,&left,&right);
		int rootidx = 0;
		if (root == 'A') {
			rootidx = 1;
			arr[rootidx] = 'A';
		}
		else {
			rootidx = findRoot(root);
		}
		if (left != '.') {
			arr[rootidx * 2] = left;
		}
		if (right != '.') {
			arr[rootidx * 2+1] = right;
		}
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
	printf("\n");
	return 0;
}