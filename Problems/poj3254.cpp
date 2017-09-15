#include <stdio.h>
#include <string.h>

#define mov(x) (1 << (x - 1))
#define chk(s1, s2) (s1 & s2)
#define sta(pos) stat[pos]

const int maxn = 13;
const int mod = 100000000;

int stat[1 << maxn], scnt, m, n, f[maxn][1 << maxn], map[maxn];

int main() {
	scanf("%d %d", &m, &n);
	int t;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &t);
			if (!t)
				map[i] |= mov(j);
		}
	for (int i = 0; i < (1 << n); i++)
		if (!chk(i, i << 1))
			stat[++scnt] = i;
	for (int i = 1; i <= scnt; i++)
		if (!chk(map[1], sta(i)))
			f[1][i] = 1;
	for (int i = 2; i <= m; i++) {
		for (int st = 1; st <= scnt; st++) {
			if (chk(sta(st), map[i]))
				continue;
			for (int st2 = 1; st2 <= scnt; st2++)
				if (!chk(sta(st), sta(st2)) && !chk(sta(st2), map[i - 1]))
					f[i][st] += f[i - 1][st2];
		}
	}
	int ans = 0;
	for (int i = 1; i <= scnt; i++)
		ans = (ans + f[m][i]) % mod;
	printf("%d\n", ans);
	return 0;
}
