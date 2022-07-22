#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int l, m,a[15],f[15];//系数
//裸矩阵快速幂 已知递推式
struct Matrix {
  int matrix[15][15];
} ori, res;

void init(int n) {
  memset(res.matrix, 0, sizeof ori);
  memset(ori.matrix, 0, sizeof ori);
  for (int i = 1; i <= n; i++) res.matrix[i][i] = 1;  //单位矩阵
  for (int i = 2; i <=n; i++) {
    ori.matrix[i][i - 1] = 1;
  }
}
Matrix mul(Matrix a, Matrix b) {
  Matrix ret;  //储存
  memset(ret.matrix, 0, sizeof ret.matrix);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      for (int k = 1; k <= 10; k++) {
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
for(int i=0;i<10;i++)f[i]=i;
  while (cin >> l >> m) {
   init(10);
    for (int i = 1; i <= 10; i++){
        cin>>a[i];
        ori.matrix[1][i]=a[i];
    }
int ans = 0;
    if (l >=10) {
      ksm(ori, l-9);
      for(int i=1;i<=10;i++){
      ans+=res.matrix[1][i]*f[10-i];
      }
    } else {
     ans=l;
    }
    cout << ans % m << endl;
  }
  return 0;
}
