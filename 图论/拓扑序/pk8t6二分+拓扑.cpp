#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
# pragma GCC optimize(3)
#define int long long
using namespace std;
//   不能成环
//如果环中有小于h的边则一定可以使其不成环 所以只需判断删去这些边后是否还有环即可
// 最小值 --》二分
// 将小于h的边删去 （入度--） 大于x的边跳过
const int N = 5e5 + 5;

int T, n, m, a[N];
int u[N], v[N], h[N];
int head[N], tot;
int in[N], rin[N];  // rin存删边后in
struct Edge {
  int from, to, w, next;
} e[N*2];
void add(int u, int v, int w) {
  e[++tot].to = v;
  e[tot].w = w;
  e[tot].next = head[u];
  head[u] = tot;
}
bool check(int x) {
  for (int i = 1; i <= n; i++) rin[i] = in[i];
  for (int u = 1; u <= n; u++) {
    for (int i = head[u]; ~i; i = e[i].next) {
      int v = e[i].to;
      int dep = e[i].w;
      if (dep <= x) rin[v]--;  // 已删该边   入度减去
    }
  }
  // 拓扑判环
  queue<int> que;  // 有向图 不用标记
  for (int i = 1; i <= n; i++)
    if (!rin[i]) que.push(i);

  int ans = 0;  //出队数   入队数也可
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    ans++;
    for (int i = head[u]; ~i; i = e[i].next) {
     int  dep = e[i].w;
      if (dep <= x) continue;
       int v = e[i].to;
      --rin[v];
      if (rin[v] == 0) que.push(v);
    }
  }
  return ans == n;  // 是否成环
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  
  memset(head, -1, sizeof head);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> h[i];
    add(u[i], v[i], h[i]);
    in[v[i]]++;
  }
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r)>>1;
    if (check(mid))
      r= mid;
    else
      l = mid + 1;
  }

  cout << l << endl;

  return 0;
}
