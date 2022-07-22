#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 5e5+5;
const int inf = 2147483647;
int m, n, s;                               // vis标记入队
int head[N], vis[N], dis[N], tot, neg[N];  //判断负环  每个点松弛次数不超过n-1
struct node {
  int from, to, next, w;
} edge[M];
void add(int u, int v, int w) {
  edge[++tot].from = u;
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot;
}
void init() {
  tot = 0;
  memset(head, -1, sizeof head);
  memset(vis, 0, sizeof vis);
  memset(neg, 0, sizeof neg);
}
int spfa(int s) {
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[s] = 0;
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].to;
      int dist = edge[i].w;
      if (dis[v] > dis[u] + dist) {  //松弛操作
        dis[v] = dis[u] + dist;
        if (!vis[v]) {  //只要不在队中就入队     可能多次
          vis[v] = 1;
          que.push(v);
  //        neg[v]++;
 //         if (neg[v] > n) return -1;  //判断负环；
        }
      }
    }
  }
  return 0;
}
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  init();
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    // add(b,a,c);    //无向图
  }
  int ans = spfa(s);
  if (ans == 0) {
    for (int i = 1; i <= n; i++) {
      cout << dis[i] << " ";
    }
  } else
    cout << "-1";
  return 0;
}
