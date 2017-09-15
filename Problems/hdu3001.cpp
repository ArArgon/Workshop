#include <stdio.h>
#include <string.h>

const int maxn = 11;
const int inf = 1e9 + 7;

int f[maxn][(maxn << 1) << 1], map[maxn][maxn];

#define mov(x) (1 << (x - 1))
#define S1(x) (mov(x) + 1)
#define S2(x) (mov(x) + 2)
#define stat(st, x) (((st & S2(x)) << 1) + (st & S1(x))))
#define low(st, x) (stat(st, x) == 2 ? (st ^= S2(x), st |= S1(x)) : (S1(x)))

int main() {
	//f[i][s] = min(f[j][s
	return 0;	
} 
