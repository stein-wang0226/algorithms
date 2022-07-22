#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//题意:S[a+b] - S[a-1] > C  ------> S[a+b] - S[a-1] >= C+1　　-->　　
// lt:S[a+b] - S[a-1] < C　　-->　　S[a+b] - S[a-1] <= C-1　　-->　
//分析：差分约束方程，将<转化为<=号，判负环
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int inf = 0x3f3f3f3f;
int n, m;                                  // vis标记入队
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
  memset(edge, 0, sizeof edge);
  memset(head, -1, sizeof head);
  memset(vis, 0, sizeof vis);
  memset(neg, 0, sizeof neg);
}
int spfa(int s) {  //最短路
 memset(dis,0x3f,sizeof dis);
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
          neg[v]++;
          if (neg[v] >n+1) return 0;  //判断负环； 尽量取大（取n wa麻了）
        }
      }
    }
  }
  return 1;
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n, n) {
    cin >> m;
    init();
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      string ss;
      cin >> a >> b >> ss >> c;  //
      if (ss == "gt") {          //  sa-sb>=c+1
        add(a + b, a-1 , -c - 1);
      } else if (ss == "lt") {
        add(a-1, a + b,  c-1);
      }
    }
    for(int i=0;i<=n;i++)add(n+1,i,0);//源点 对每个点跑spfa
    int ans = spfa(n+1);//
    if (ans)
      printf("lamentable kingdom\n");
    else
      printf("successful conspiracy\n");
  }
  return 0;
}
