#include <cstdio>
#include <vector>
#define MAXN 1000010
#define ll long long

using namespace std;
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
	if (a <= l && r <= b) return 1;//tree[node];
	return query(node * 2, l, (l + r) / 2, a, b) + query(node * 2 + 1, (l + r) / 2 + 1, r, a, b);
}

int main() {
	int N, M, K, T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d",&N,&M);
		init(1, 1, N);
		for (int i = 1; i <= M; i++) {
			int v, a, b;
			ll diff;
			scanf("%d", &v);
			query(1, 1, N, 1, v);
			for (int j = v; j >= 1; j--) {
				update(1, 1, N, 1, v);
			}
		}
	}
	return 0;
}
