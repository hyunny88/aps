#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long

vector<ll> tree;
vector<ll> arr;

// ���ʷ� SegmentƮ���� ��ǥ���� �����ϴ� �Լ�
ll init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	else return tree[node] = init(node * 2, l, (l + r) / 2) + init(node * 2 + 1, (l + r) / 2 + 1, r);
}

// idx ��° ���� v�� ������Ʈ�ϴ� �Լ�
ll update(int node, int l, int r, int idx, int v) {
	if (idx < l || r < idx) return tree[node];
	if (l == r) return tree[node] = v;
	return tree[node] = update(node * 2, l, (l + r) / 2, idx, v) + update(node * 2 + 1, (l + r) / 2 + 1, r, idx, v);
}

// ����° ������ b��° �� ������ ���� ���ϴ� �Լ�
ll query(int node, int l, int r, int a, int b) {
	if (b < l || r < a) return 0;
	if (a <= l && r <= b) return tree[node];
	return query(node * 2, l, (l + r) / 2, a, b) + query(node * 2 + 1, (l + r) / 2 + 1, r, a, b);
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	arr = vector<ll>(N + 1);
	tree = vector<ll>(N * 4);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}
	init(1, 1, N);
	for (int i = 1; i <= M + K; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			update(1, 1, N, b, c);
		}
		else {
			printf("%lld\n", query(1, 1, N, b, c));
		}
	}

	return 0;
}
