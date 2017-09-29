# Möbius Inversion Formula (莫比乌斯反演)
---
## 定义与约定
算术函数：
> 在数论上，**算术函数**（或称数论函数）指定义域为正整数、陪域（又称上域，可以理解为值域，但值域只是陪域的子集）为复数的函数，即 $f:\mathbb {Z} ^{+}\rightarrow \mathbb {C}$。
> - **理解上域与值域关系：** 设函数 $f$为一个实函数，即：
$f:\mathbb {R} \rightarrow \mathbb {R}$，
定义
$f\colon \,x\mapsto x^{2}$\
这里 $f$ 的上域为实数集 $\mathbb {R}$，但明显地函数 $f(x)$ 不会有负的函数值，因此，事实上这里的值域为非负实数集 ${\mathbb  {R}}^{+}\cup \{0\}$，即 $[0,+\infty)$

莫比乌斯函数：
> 莫比乌斯函数 $\mu$ 是指以下的函数：
> $$ {\displaystyle \mu (n)={\begin{cases}1\quad \quad  \quad (n=1)\\(-1)^{k} \quad 若 {\displaystyle n\,}为无平方数因数，且{\displaystyle n=p_{1}p_{2}......p_{k}\,}(p_i均为互异素数)\\0  \quad \quad\quad 若 {\displaystyle n\,},有大于 {\displaystyle 1\,},的平方数因数\\\end{cases}}}$$
>
> 莫比乌斯函数性质：
> 1. $${\displaystyle \sum _{d|n}\mu (d)={\begin{cases}1 \quad {\displaystyle n=1\,}\\0 \quad n > 1\end{cases}}} $$
> 2. $$\sum_{d|n} \frac{\mu (d)} {d} = \frac {\varphi (n)} {n} \quad \varphi(n)为欧拉函数$$
> 3. $μ(n)$ 是积性函数

## 莫比乌斯反演公式
> 如果 $f$ 和 $g$ 是*算数函数*，并且满足
> $$g(n)=\sum_{d\,\mid \,n}f(d)\quad n\in \mathbb{Z}^+ \text{ and }n \ge 1$$
> 那么
> $${\displaystyle f(n)=\sum _{d\,\mid \,n}\mu (d) \cdot g\left({\frac {n}{d}}\right)\quad n\in \mathbb{Z}^+ \text{ and }n \ge 1}$$
> 其中 $\mu$ 是**莫比乌斯函数**，并且和值取到了$n$的**每个正整数因数**。

> **说明**：
> 1. 公式表明，函数 $f(n)$ 可以从函数 $g(n)$ 推出。
