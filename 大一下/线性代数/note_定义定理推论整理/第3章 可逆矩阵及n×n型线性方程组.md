## 第3章	可逆矩阵及$n\times n$型线性方程组

**定义 3-1**	对于$n$阶方阵$\bold A$，若存在$n$阶方阵$\bold B$，使得
$$
\bold {AB} = \bold {BA} = \bold E
$$
则$\bold A$叫做**可逆矩阵**（或称$\bold A$可逆），$\bold B$叫做$\bold A$的逆矩阵.否则，称$\bold A$不可逆

**定理 3-1**	若$\bold A$是可逆矩阵，则$\bold A$的逆矩阵是唯一的

**定义 3-2**	设$n>1$，$\bold A=\left[\matrix{a_{ij}\matrix}\right]_{m\times n}$，把矩阵
$$
\bold A^*=
\left[
\matrix{
A_{11} & A_{21} & \cdots & A_{n1} \\
A_{12} & A_{22} & \cdots & A_{n2} \\
\vdots & \vdots &  & \cdots \\
A_{1n} & A_{2n} & \cdots & A_{nn}
\matrix}
\right]
$$
叫做$\bold A$的伴随矩阵。

**定理 3-2**	设$\bold A$是n阶方阵，$n>1$，则
$$
\bold {AA^*} = \bold {A^*A} = |\bold A|\bold E
$$
**定理 3-3**	方阵$\bold A$可逆的充要条件是$|\bold A|\neq 0$.并且当$\bold A$可逆时，
$$
|\bold A^{-1}|=\frac{1}{\bold A},
\ \ \ \ \ \ \ 
\bold A^{-1}=\frac{\bold A^*}{|\bold A|}
$$
**定义 3-3**	对于方阵$\bold A$ ，当$|\bold A|=0$时，称$\bold A$为奇异矩阵；当$|\bold A|\neq 0$时，称$\bold A$为非奇异矩阵.

**推论 3-1**	若方阵$\bold A$和$\bold B$满足$\bold {AB}=\bold E $，则$\bold A$和$\bold B$都可逆，且$\bold A^{-1}=\bold B$，$\bold B^{-1}=\bold A$.

根据**推论 3-1**可以证明，可逆阵$\bold A$具有下列性质：
（1）$\bold A^{-1}$也可逆，且$(\bold A^{-1})^{-1}=\bold A$；
（2）$\bold A^T$也可逆，且$(\bold A^T)^{-1}=(\bold A^{-1})^T$ ；
（3）若数$k\neq 0$，则$k\bold A$也可逆，B且$(k\bold A)^{-1}=k^{-1}\bold A^{-1}$；
（4）若$\bold A$和$\bold B$是同阶可逆矩阵，则$\bold {AB}$也可逆，且$(\bold A\bold B)^{-1}=\bold B^{-1}\bold A^{-1}$.
特别地，若$\bold A$可逆，则$\bold A^k$也可逆，且$(\bold A^k)^{-1}=(\bold A^{-1})^k$.

**定理 3-4**	方阵$\bold A$可逆的充要条件是$\bold A$能表示成有限个初等矩阵的乘积。

**推论 3-2**	方阵$\bold A$可逆的充要条件是$\bold A$与$\bold E$等价.

**推论 3-3**	在矩阵$\bold A$的左（右）端乘以可逆矩阵$\Longleftrightarrow$对$\bold A$进行有限次初等行（列）变换。

**推论 3-4**	$m\times n$型矩阵$\bold A$与$\bold B$等价（相抵）的充要条件是存在$m$阶可逆矩阵$\bold P$和$n$阶可逆矩阵$\bold Q$，使得$\bold {PAQ}=\bold B$.

**定理 3-5**	$n\times n$型齐次线性方程组$\bold {Ax}=0$只有零解（有非零解）的充要条件是$|\bold A|\ne 0(|\bold A|=0)$.

**定理 3-6**	$n\times n$型非齐次线性方程组$\bold {Ax}=\bold b$有唯一解的充要条件是$|\bold A|\ne 0$（即$\bold A$可逆），其解为$\bold x=\bold A^{-1}\bold b$.

**定理 3-7**	【克拉默（Cramer）法则】 当$|\bold A|\ne 0$时，$n\times n$型非齐次线性方程组$\bold {Ax}=\bold b$有唯一解
$$
\bold x_i=\frac{|\bold B_i|}{|\bold A|}(i=1,2,\cdots,n),
$$
其中，$\bold B_i$是把$\bold A$的第$i$列换为$\bold b$所得的矩阵。

