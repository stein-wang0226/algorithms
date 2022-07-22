#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//求从起点1到每个点的最短路然后再回到起点1的最短路之和。
//即正图和反图之和
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n,m,T;  // vis标记入队
int head[N], vis[N], dis[N], tot;
int a[N],b[N],w[N],ans[N];
struct Edge {
  int from, to, next, w;
} edge[M];
struct node {
  int id, w;
  bool operator<(const node &b) const { return b.w < w; }
};

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
  memset(dis,0x3f,sizeof dis);

}
void dij(int s) {
  priority_queue<node> que;
  dis[s]=0;
  que.push({s, 0});
  while (!que.empty()) {
    node u = que.top();
    que.pop();
    int cur = u.id;
    if (vis[cur]) continue;
    vis[cur] = 1;
    for (int i = head[cur]; ~i; i = edge[i].next) {
      int v = edge[i].to;
      int dist = edge[i].w;
      if (dis[v] > dis[cur] + dist) {
        dis[v] = dis[cur] + dist;
        que.push({v, dis[v]});
      }
    }
  }
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

cin>>T;
while(T--){
  int sum=0;
cin>>n>>m;
//+
init();
memset(ans,0,sizeof ans);
for(int i=1;i<=m;i++){
  cin>>a[i]>>b[i]>>w[i];
  add(a[i],b[i],w[i]);
}
dij(1);
for(int i=2;i<=n;i++){
  ans[i]=dis[i];
}
init();
for(int i=1;i<=m;i++){
  add(b[i],a[i],w[i]);
}
dij(1);
for(int i=2;i<=n;i++){
  sum+=ans[i];
  sum+=dis[i];
}
cout<<sum<<endl;
}
  return 0;
}
