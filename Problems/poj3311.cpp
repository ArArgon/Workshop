#include <stdio.h>
#include <string.h>

const int maxn = 11;
const int inf = 1e9 + 7;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define mov(x) (1 << (x - 1))

int f[maxn][1 << maxn], n, map[maxn][maxn];

int main() {
	while(true) {
		scanf("%d", &n);
		if (!n)	break;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				scanf("%d", &map[i][j]);
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		for (int s = 0; s <= (1 << n) - 1; s++)
			for (int i = 1; i <= n; i++) {
				if(!(mov(i) & s))
					continue;
				if (mov(i) == s) {
					f[i][s] = map[0][i];
					continue;
				}
				f[i][s] = inf;
				for (int j = 1; j <= n; j++) {
					if ((mov(j) & s) && j != i)
						f[i][s] = min(f[i][s], f[j][s ^ mov(i)] + map[j][i]);
				}
			}
		int ans = inf;
		for (int i = 1; i <= n; i++)
			ans = min(ans, f[i][(1 << n) - 1] + map[i][0]);
		printf("%d\n", ans);
	}
	return 0;
} 
