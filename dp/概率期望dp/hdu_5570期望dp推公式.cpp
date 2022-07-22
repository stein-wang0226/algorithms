#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e3 + 5;
int T, n, m, a[N];
double p[N][N];
double sum[N];  //
//共 n个球 ，共m种颜色 ，第i个求颜色为 j的概率为  ai,j/(ai,1+ai,2+...ai,m)
// 对于第i种颜色 ，若右x个球 则对答案贡献为n^2;
// 思路： 贡献为n^2 ---> 期望的对数是多少  （某种颜色总对数的期望）
// （两个相同的也算一对）
// 假设p[i][j]表示第一个位置出现颜色为j的的概率是多少，那么我们可以推出来该颜色期望的对数的公式是
// ans = p[i][1] + p[i][2]+ ... + p[i][m] + p[i][1]*p[i][2] + p[i][1]*p[i][3] +
// .... + p[i][2]*p[i][1]+ ... + p[i][m]*p[i][m-1] 然后化简，就可以得到ans =
// sigma(p[i][k]) + sigma(p[i][k]) * sigma(p[i][k]) - sigma(p[i][k]*p[i][k])
// 就可以On来处理答案

void solve() {
  for (int i = 1; i <= n; i++) {
    sum[i] = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%d",&p[i][j]);
      sum[i] += p[i][j];
    }
  }
  double ans = 0;
  for (int j = 1; j <= m; j++) {
    double s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
      double pi = p[i][j] / sum[i];
      s1 += pi;
      s2 += pi * pi;
    }
    ans += s1 + s1 * s1 - s2;
  }
  printf("%.2lf\n", ans);
}
signed main() {
  while (~scanf("%d%d",&n,&m)) {
    solve();
  }
  return 0;
}
