#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//  高斯消元求解 线性方程组
using namespace std;
const int N = 310;
const double eps = 1e-8;  //   0
double a[N][N];           //矩阵
// n行  n+1列
int T, n,m;

// 遍历列  ， 将该列中最大的 对应那行换到顶端(不为0，为0则下一列)  ，再用改行首元素将下面的都消0，固定改行  处理下一列
// 非0行数即为秩 




int guass() {  // 高斯消元，答案存于a[i][n]中，0 <= i < n
  int c, r;
  for (c = 0, r = 0; c < m; c++) {  //遍历每一列  先将消为阶梯型  行和列是同步的
    int t = r;  //  r 初值为0   每次完整做一列非全0， r++
    for (int i = r; i < n; i++)
      if (fabs(a[i][c] > fabs(a[t][c]))) t = i;  //   找该列 绝对值最大的 那一行
    if (fabs(a[t][c]) < eps) continue;  //该列都为0则不用消 下一列

    for (int i = c; i < m; i++)//前面0不用换
      swap(a[t][i], a[r][i]);  // 将绝对值最大的行换到顶端 (除固定行外第一行)
    for (int i = m-1; i >= c; i--)
      a[r][i] /= a[r][c];//将当前行的首位变一，(整行同乘) ，从后往前防止a[r][c]改变影响
    for (int i = r + 1; i < n; i++)  // 用当前行将下面所有列消0
      if (fabs(a[i][c]) > eps)       //对非0 操作
        for (int j = m-1; j >= c; j--) a[i][j] -= a[r][j] * a[i][c];  //首位消为0
    r++;  //销完一列 固定一行
}

  return r;  // 秩
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n>>m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

      int r = guass();
    cout << n - r << endl;
    return 0;
  }