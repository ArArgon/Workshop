# $Tarjan$ 算法（二）: 割顶和桥
--------
## 约定
> 我们访问每一个点。在DFS森林中的边称为树边，第一次处理时从后代指向祖先的边称为反向边。然而在无向图中，除了树边，其他边都是反向边（有向图还有正向边和横叉边）。\
\
> 对于无向连通图G:
> * **割顶** 是去掉以后让图不连通的点
> * **桥（割边）** 是去掉以后让图不连通的边

-------

## 割顶
对于无向图。我们讨论一个点是不是割顶，需要分两种情况：

> 1. 这个点是DFS树的根节点，那么它是割顶，当且仅当它有**两个或以上数目的儿子**.
> 2. 这个点不是DFS树的根节点，那么它**没有可以到达它的祖先的反向边的子孙**.

所以，如何求割顶?
* 判断一个点是不是割顶就需要$low$值来判断 ($low$值是它通过边或者它的子孙所能到达的节点的$dfn$值中最小的$dfn$值)
    1. 它是根节点，那么它满足$Count_{Son} \ge 2$.
    2. 它不是根节点，那么$dfn[now] \le low[now]$ *(仔细理解)* , 并且$Father[now] \ne Root$.

**Code:**
```c++
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v, u);
            if (u == root) {//如果根节点是割点，当且仅当它有两个及以上的儿子
                root_cnt++;
                if (root_cnt > 1 && !cut[u])
                    cut[u] = true;
            }
            else {
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                    cut[u] = true;  //如果满足这个条件则 u 为割点    
            }
        }
        else if (v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}
```

------

## 桥

若一条无向边 $(u,v)$ 是桥，需满足：
> 当且仅当无向边 $(u,v)$ 是树边的时候，需要满足$dfn(u) < low(v)$ **(注意不能取等号)**， 也就是$v$向上翻不到$u$及其以上的点，那么 $u-v$ 之间一定能够有1条或者多条边不能删去，因为他们之间有一部分无环，是桥。

为什么不能取等号？
> 如果$v$能上翻到$u$，那么 $u-v$ 就是一个**环**。删除其中一条边后，图仍然是连通的。

**Code:**
```c++
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++cnt;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                cut[u][v] = true;  //如果满足这个条件则adj(u, v)为割边
        }
        else if (f != v)
            low[u] = min(low[u], dfn[v]);
    }
}
```
