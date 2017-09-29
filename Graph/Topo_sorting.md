#Topological Sorting (拓扑排序)
---
## 定义与约定
> **偏序与全序**
> - **偏序** 可以认为是有向无环图中无先后顺序的两点。
> - **全序** 可以认为是有向无环图中有先后顺序的两点。
>
> 说明：  一个 DAG 的拓扑排序是唯一的，当且仅当这个图上任意两点都是*全序*关系.

## Kahn Algorithm
### 伪代码 (from wiki)
```c
L ← Empty list that will contain the sorted elements //初始为空，储存排序后元素
S ← Set of all nodes with no incoming edges          //储存所有无入读的节点
while S is non-empty do                              //当 S 非空
    remove a node n from S                           //取出节点 n
    insert n into L                                  //加入 L
    for each node m with an edge e from n to m do     //枚举所有与 n 通过边 e 相连的节点 m
        remove edge e from the graph                 //删除边 e
        if m has no other incoming edges then        //如果此时 m 仍然无入度
            insert m into S                          //将 m 加入 S
if graph has edges then                              //如果此时图仍然有边
    return error (graph has at least one cycle)      //有环
else
    return L (a topologically sorted order)          //返回拓扑序
```

### 算法详解
结合注释，应该可以看出这个算法十分的简单。\
具体如下:
* 创建一个集合 $S$ 和一个List $L$，其中 $S$ 存储当前图中入度为 $0$ 的节点
* 当 $S \ne \emptyset$ 时
    * 从 $S$ 中弹出节点 $n$
    * 将 $n$ 加入 $L$
    * 枚举所有与 $n$ 通过边 $e$ 相连的节点 $m$ *(其实也可看作删去 $v$ 的一个入度)*
        * 将 $e$ 删除
        * 如果入度为$0$
            * 将 $m$ 加入$S$
* 如果 $\exists \space e \in G$
    * 则此该图有至少一个环
* 否则：$L$ 为该图的一个拓扑排序

注意：该算法要维护一个入度为$0$的集合$S$，而从伪代码中可以看出：对于$n$的选取顺序无关 *(体现了偏序关系无序的特点)*
因此，维护$S$可以是栈，队列以及其他数据结构。

时间复杂度 $O(|E| + |V|)$
### Code
```c++
// n: the number of nodes
vector<int> lst;
queue<int> s;
bool Kahn() {
	for (int i = 1; i <= n; i++)
		if (!in[i])
			s.push(i);
	while(!s.empty()) {
		int u = s.front();
		s.pop();
		lst.push_back(u);
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			in[v]--;
			if (!in[v])
				s.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		if (in[i])
			return false;
	return true;
}
```
## Depth First Search
### 伪代码 (from wiki)
```c++
L ← Empty list that will contain the sorted nodes       //同上
while there are unmarked nodes do                       //访问没有被标记的点
    select an unmarked node n
    visit(n)                                            //调用 visit
function visit(node n)
    if n has not been visited yet then                  //若 n 未被访问过
        mark n as visited                               //标记 n
        for each node m with an edge from m to n do     //枚举与 n 相连的点 m
            visit(m)                                    //递归
        add n to L                                      //将 n 加入 L
```

Very simple. 用 DFS 实现拓扑排序，实际上最核心的一句话是 `add n to L`. 但是注意：**将 $n$ 加入$L$ 是在访问完所有与其相连的边之后**。

为什么在访问完所有与 $n$ 相连的边之后将 $n$ 加入$L$ ，最终 $L$ 就是拓扑排序呢？
> 因为在 $\text{DFS}$ 即将退出时，理论上 *(图是DAG)* 所有与 $e$ 相连的节点都应被访问过了，**即当前节点是一条路径上的最后一个节点**。

正确性证明：
考虑一条边 $u-v$，$\mathrm{visit}(u)$ 只有$3$种情况：
1. $vis[u]=\mathrm{false}$，然后 $\mathrm{visit}(v)$ 返回之后返回
2. $vis[u]=\mathrm{true}$，并且调用 $\mathrm{visit}(v)$ 返回。
3. $vis[u]=\mathrm{true}$，但是此时调用 $\mathrm{visit}(v)$ 未返回。

显然第三种情况是不可能的 *(如果成立，那么$u-v$就有一条路径)*

而对于情况1, 2 所有的节点，$u$ 都会比 $v$ 先加入$L$

时间复杂度$O(|V|+|E|)$，同 Kahn
```c++
vector<int> g[N];
int vis[N], topo[N], cnt;

bool dfs(int u) {
    vis[u] = -1; //-1用来表示顶点u正在访问
    for(int i = 0; i < g[u].size(); i++)
        if(vis[g[u][i]] == -1) //表示这个点进入了两次，肯定出现了环
            return false;
        else if(vis[g[u][i]] == 0)
            dfs(g[u][i]);
    vis[u] = 1;
    topo[cnt++] = u; //放到结果数组里，输出的时候记得倒序输出，（回溯的原因）
    return true;
}

bool toposort(int n) {
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            if(!dfs(i))
				return false; //circle
    return true;
}
```
