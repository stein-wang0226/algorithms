#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 100;
//平面上有N个点，选k个点使其中各点对距离的最小值最大
// 二分+最大团check
//如果已知距离的最小值mid，判定是否存在k个点且两两距离均超过mid。
//将距离大于等于mid的点连边求一下最大团即可。******
//最大团随机比较快。由于平面的特殊性，随机 n*n 次即可。
int T, n, a[N], k, U[N];
int x[N], y[N];
int ans = 0;
bool Map[N][N];
inline double dis(int i, int j) {  // i,j距离
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
inline bool is_clique(int num, int node) {  // 判断node 能否入团
  for (int i = 1; i <= num; i++) {
    if (!Map[U[i]][node]) return false;
  }
  return true;
}

void dfs(int depth, int cur) {
  if (n - cur + depth + 1 <= ans) return;
  if (ans >= k) return;
  for (int i = cur; i <= n; i++) {
    if (is_clique(depth, i)) {
      U[depth + 1] = i;
      dfs(depth + 1, i + 1);
    }
  }
  ans = max(ans, depth);
}
int check(double x) {
  memset(Map, 0, sizeof Map);
  for (int i = 1; i <= n; i++) {  /// 双向
    for (int j = 1; j <= n; j++) {
      if (dis(i, j) >= x) Map[i][j] = 1;
    }
  }
  ans = 0;
  dfs(0, 1);
  return ans >= k;
}
signed main() {


  vector<double> v;  //距离
  while (~scanf("%d %d",&n,&k)) {
    for (int i = 1; i <= n; i++) scanf("%d %d",&x[i],&y[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        v.push_back(dis(i, j));
      }
    }
    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (check(v[mid]))
        l = mid;
      else
        r = mid - 1;
    }
    printf("%.2lf\n", sqrt(v[l]));
  }
  return 0;
}
