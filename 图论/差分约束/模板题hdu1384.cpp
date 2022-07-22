#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//题意:有n个如下形式的条件:ai bi ci,表示在区间[ai,
//bi]内至少要选择ci个整数点.问你满足n个条件的情况下,最少需要选多少个点?
//设Si为[0,i]选点的个数(前缀和) 则Sbi-Sa(i-1)>=ci  又有  整数点   0<=Si-Si<=1
//求Smax-Smin 最小值->最长路 统一为>=

const int N = 5e4 + 5;
const int M = 5e5+5;
const int inf = 0x3f3f3f3f;
int n,maxx,minn;                                     // vis标记入队
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
  memset(edge,0,sizeof edge);
  memset(head, -1, sizeof head);
  memset(vis, 0, sizeof vis);
  memset(neg, 0, sizeof neg);
}
int spfa(int s) {  //最长路
  for (int i = 1; i <= maxx; i++) dis[i] = -inf;
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
      if (dis[v] < dis[u] + dist) {  //松弛操作
        dis[v] = dis[u] + dist;
        if (!vis[v]) {  //只要不在队中就入队     可能多次
          vis[v] = 1;
          que.push(v);
          neg[v]++;
          if (neg[v] > n) return 0;  //判断负环；
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
  while (cin >> n) {
    init();
     maxx = 0, minn = inf;
    for (int i = 1; i <= n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      maxx = max(maxx, b);
      minn = min(minn, a - 1);
      add(a - 1, b, c);  //   Sb-S(a-1)>=c
    }
    for (int i = minn + 1; i <= maxx; i++) {  //    Si - Si-1 >=0  Si-1 -Si>=-1
      add(i - 1, i, 0);
      add(i, i - 1, -1);
    }
    int ans = spfa(minn);
    if (!ans) {
      cout << dis[maxx] << endl;
    }
    else cout<<"-1"<<endl;
  }

  return 0;
}
