#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 5e5+5;
const int inf = 2147483647;
int m, n, s;                               // vis������
int head[N], vis[N], dis[N], tot, neg[N];  //�жϸ���  ÿ�����ɳڴ���������n-1
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
      if (dis[v] > dis[u] + dist) {  //�ɳڲ���
        dis[v] = dis[u] + dist;
        if (!vis[v]) {  //ֻҪ���ڶ��о����     ���ܶ��
          vis[v] = 1;
          que.push(v);
  //        neg[v]++;
 //         if (neg[v] > n) return -1;  //�жϸ�����
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
    // add(b,a,c);    //����ͼ
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
