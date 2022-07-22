#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//#define int long long
// SAS u v 表示 v开始后 u 才能开始；f(u)>=f(v);
// SAF u v 表示 v结束后 u 才能开始；f(u)>=f(v)+a[v]
// FAF u v 表示 v结束后 u 才能结束；f(u)+a[u]>=f(v)+a[v];
// FAS u v 表示 v开始后 u 才能结束；f(u)+a[u]>=f(v);
// f[1]=0;                     求 f[i]  即 f[i]-f[1]
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n;                         // vis标记入队
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
int spfa(int s) {  //最长路   正环
  for (int i = 1; i <= n; i++) dis[i] = -inf;
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
  int a[N];  //持续时间
  int Case =0;
  while (cin >> n, n) {
     cout<<"Case "<<++Case<<":"<<endl;
         init();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
     add(0,i,0);
    }
    string ss;

    while (cin >> ss && ss != "#") {
      int u, v;
      cin >> u >> v;
      if (ss == "SAS") add(v, u, 0);// u,v 顺序
      if (ss == "SAF") add(v, u, a[v]);
      if (ss == "FAF") add(v, u, a[v] - a[u]);
      if (ss == "FAS") add(v, u, -a[u]);
    }
    
    int ans=spfa(0);
    if(ans){
      for(int i=1;i<=n;i++){
        cout<<i<<" "<<dis[i]<<endl;
      }
      cout<<endl;
    }
    else {cout<<"impossible"<<endl;
  cout<<"\n";}
  }
    return 0;
  }
