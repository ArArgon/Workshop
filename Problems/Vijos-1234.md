# 最小生成树 - 口袋的天空
`Vijos - 1234` `生成树` `最小生成树`
### Links: [Vijos-1234](https://vjudge.net/problem/POJ-3311)
---

# 题目大意
> 已知$n$个节点，$m$条边，求图中最小$k$个生成树.\
> $n \le 10^3 \space , m \le 10^5, \space k \le 10$

#题目解析
比较水吧。

你想想：一个$MST$是不是图中最小$1$个生成树，而将其中最大的$k-1$条边断开是不是意味着这$k$个子树是不是最小的$k$个生成树？答案即是$MST$的边权和减去最大$k-1$条边的边权和.

$$ ans=\sum_{e \in MST} e.w-\sum_{p \in MaxEdge}p.w \space, MaxEdge\subsetneqq MST$$

**其实完全没有必要算完后再减，可以只算前$n-k$条边，直接出答案**

最后：注意**边界**; 注意**数组大小**

## Code
`我交了四五次，竟是fa数组开小了，用maxn竟然要WA. woc fa要开1e5`
```c++
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

int n, m, k, fa[maxm];

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
```
