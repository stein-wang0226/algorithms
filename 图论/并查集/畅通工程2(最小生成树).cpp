#include <bits/stdc++.h>
using namespace std;
int pre[1205], n, t;
int x[1205], y[1205];
void init(int n) {  //初始化为自身
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
  }
}
int find_r(int x) {      //寻找根节点函数
  while (pre[x] != x) {  //不为根
    x = pre[x];          //一直向上找
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
struct edge {
  int x, y;
  double dis;
  bool operator<(const edge &b) const { return dis < b.dis; }
} Edge[10010];
int main() {
  cin >> t;
  while (t--) {
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(Edge, 0, sizeof Edge);
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++) {  //依次合并
      cin >> x[i] >> y[i];
    }
    int cnt = 0;                   //统计有效边数
    for (int i = 1; i < n; i++) {  //生成有效边 以求最小生成树
      for (int j = i + 1; j <= n; j++) {
        double l = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                        (y[i] - y[j]) * (y[i] - y[j]));  //距离
        if (l >= 10 && l <= 1000) {
          Edge[++cnt].x = i;
          Edge[cnt].y = j;
          Edge[cnt].dis = l;
        }
      }
    }
    sort(Edge + 1, Edge + cnt + 1);
    double cost = 0;
    for (int i = 1; i <= cnt; i++) {  //最小生成树
      if (find_r(Edge[i].x) != find_r(Edge[i].y)) {
        merge(Edge[i].x, Edge[i].y);
        cost += 100.0 * Edge[i].dis;
      }
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
      if (find_r(i) == i) cnt1++;
    }
    if (cnt1 == 1)
      printf("%.1lf\n", cost);
    else
      cout << "oh!"
           << "\n";
  }
  return 0;
}
