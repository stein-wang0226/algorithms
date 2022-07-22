#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int l, m;
//先推导递推公式 ：1——f 0---m
//不含101和111的所有序列数   f(1)=2  f(2)=4 f(3)=6    f(n)=?
//因为最后两位只能是10/00  1.若第n位是0 则100
//000都满足,所以所有n-1的序列都满足此时F(n)=f(n-1)
// 2. 第n位是1   则前两位只能是01 / 00     是00时：对应前n-3位所有组合成立
// 所以此时F(n)=f(n-3) 时01时
//第n-3位还不能为1，只能为0,所以只对应n-4所有组合成立，索引f(n)=f(n-4)
// so    f(n)=f(n-1)+f(n-3)+f(n-4)  (n>4)
//构造矩阵
struct Matrix {
  int matrix[10][10];
} ori, res;

void init(int n) {
  memset(res.matrix, 0, sizeof res.matrix);
  memset(ori.matrix, 0, sizeof ori.matrix);
  for (int i = 1; i <= n; i++) res.matrix[i][i] = 1;  //单位矩阵
  for (int i = 2; i <=n; i++) {
    ori.matrix[i][i - 1] = 1;
  }
}
Matrix mul(Matrix a, Matrix b) {
  Matrix ret;  //储存
  memset(ret.matrix, 0, sizeof ret.matrix);
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= 4; k++) {
        ret.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
        ret.matrix[i][j] %= m;
      }
    }
  }
  return ret;
}

void ksm(Matrix a, int k) {
  while (k) {
    if (k & 1)  //奇数
      res = mul(res, a);

    a = mul(a, a);
    k >>= 1;
  }
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> l >> m) {
   init(4);
    for (int i = 1; i <= 4; i++)
    if (i != 2) ori.matrix[1][i] = 1;

    ksm(ori, l-4);
    int ans = 0;
    if (l > 4) {
      ans = res.matrix[1][1] * 9 + res.matrix[1][2] * 6 + res.matrix[1][3] * 4 +
            res.matrix[1][4] * 2;//反转的
    } else {
      if (l == 1) ans = 2;
      if (l == 2) ans = 4;
      if (l == 3) ans = 6;
      if (l == 4) ans = 9;
    }
    cout << ans % m << endl;
  }
  return 0;
}
