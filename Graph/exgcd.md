# Extend-Euclid Algorithm

---

## 一些定义

---

### 1. Euclid Algorithm (辗转相除法)

> 已知$a,b\in \mathbb Z$，则其**最大公因数**满足等式：
> $$\gcd(a,b)=\gcd(b,a \mathop{\mathrm{mod}} b)$$
> 这个计算两整数最大公因数的方法叫做辗转相除法 (Euclid Algorithm, 又称欧几里得算法).

### 2. Bézout's Identity (裴蜀定理)

> 对于$a,b \in \mathbb Z$，总存在一对 $(x,y)\in \mathbb Z^2$，满足：
> $$ax+by=\gcd(a,b)$$

---

## 推导过程

---

### 1. 拓展欧几里得算法
观察如下两个方程:
$$
\begin{align}
ax+by&=\gcd(a,b) \\
bx_1+\left(a-b\cdot \left\lfloor\frac a b \right\rfloor\right)y_1&=\gcd(b, a \mathop{\mathrm{mod}} b)
\end{align}
$$
由 辗转相除法 可知： $\gcd(a,b)=\gcd(b,a \mathop{\mathrm{mod}} b)$，于是有：
$$ax+by=bx_1+\left(a-b\cdot \left\lfloor\frac a b \right\rfloor\right)y_1$$
展开整理可得：
$$ax+by=ay_1+b\left(x_1-\left\lfloor\frac a b \right\rfloor y_1\right)$$
对应 $a, b$：
$$
\begin{cases}
    x=y_1 \\
    y=x_1-\left\lfloor\frac a b \right\rfloor y_1
\end{cases}
$$

在 C/C++ 中，两个整数相除默认为相除取整，于是扩展欧几里得算法代码如下：

```c++
int extgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int ans = extgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a / b) * y;
}
```
### 2. 扩展欧几里得求解方程 $ax+by=c$
