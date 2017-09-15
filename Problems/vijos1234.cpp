#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
const int maxm = 10000 + 10;
const char NA[] = "No Answer";

struct edge {
	int u, v, w;
	edge() { }
	edge(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
	bool operator < (const edge & e2) const {
		return w < e2.w;
	}
} graph[maxm];

int n, m, k, fa[maxn];

void init() {
	for (int i = 0; i <= m; i++)
		fa[i] = i;
}

int find(int x) {
	return (fa[x] != x) ? fa[x] = find(fa[x]) : x;
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = b;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	init();
	int u, v, w, edc = 0, len = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[i] = edge(u, v, w);
	}
	sort(graph, graph + m);
	for (int i = 0; i < m; i++) {
		u = graph[i].u, v = graph[i].v, w = graph[i].w;
		if (edc == n - k)
			break;
		if (find(u) != find(v)) {
			merge(u, v);
			len += w;
			edc++;
		}
	}
	if (edc != n - k) {
		puts(NA);
		return 0;
	}
	printf("%d\n", len);
	return 0;
} 
