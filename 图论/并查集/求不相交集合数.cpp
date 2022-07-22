#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int pre[1005], m, n, t;
void initial(int n) {  //初始化为自身
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
  }
}
int find_r(int x) {   //寻找根节点函数
  while (pre[x] != x) {  //不为根
    x = pre[x];       //一直向上找
  }
  return x;
}
void merge(int x, int y) {
  int root_x = find_r(x);
  int root_y = find_r(y);
  if (root_x != root_y) {  //不属于同一集合
    pre[root_x] = root_y;  //合并
  }
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> m;
    initial(n);
    for (int i = 1; i <= m; i++) {  //依次合并
      int x, y;
      cin >> x >> y;
      merge(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (find_r(i) == i) cnt++;  //根的个数
    }
    cout << cnt << "\n";
  }
    return 0;
  }