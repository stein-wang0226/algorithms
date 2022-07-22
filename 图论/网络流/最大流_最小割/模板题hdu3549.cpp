#include <bits/stdc++.h>
#define LOCAL
using namespace std;
#define inf 0x3f3f3f3f;  // inf
//#define int long long
// EK
int T;

const int MAXN = 105;           // DIAN
const int MAXM = 5005;          // BIAN
int n, m, s, t, u, v;
int tot;  //边序号从2开始  (0~1),  2~3  4~5
int w, ans, minflow[MAXN];      //起点到i可以增加的流量
int vis[MAXN], pre[MAXN];       //记录前驱边
int head[MAXN];                 //链式前向星  点i对应起始边
int flag[MAXN][MAXN];           //标记点对应边编号  处理重边
struct EDGE {
  int to, next;
  int flow;         //剩余流量
} edge[MAXM << 1];  //反向边双倍

void add(int u, int v, int w) {  //同时加正反两条边
  edge[++tot].to = v;
  edge[tot].flow = w;
  edge[tot].next = head[u];
  head[u] = tot;
  edge[++tot].to = u;
  edge[tot].flow = 0;  //反向弧初始化为0
  edge[tot].next = head[v];
  head[v] = tot;
}

int bfs(int s, int t) {  // bfs 寻找增广路(s->t每条边剩余流量都为正的路径)
  for (int i = 1; i <= n; i++) vis[i] = 0;
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  minflow[s] = inf;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; ~i; i = edge[i].next) {  //遍历边
      if (edge[i].flow == 0) continue;             //无剩余流量跳过
      int v = edge[i].to;
      if (vis[v] == 1) continue;
      minflow[v] = min(minflow[u], edge[i].flow);
      pre[v] = i;  //记录前驱边
      que.push(v);
      vis[v] = 1;
      if (v == t) return 1;  //跳出  找到一条增广路
    }
  }
  return 0;
}

void update(int s, int t) {  // 增广操作， 答案加上
  int u = t;
  while (u != s) {  //从t->s 通过pre[]  遍历路径
    int v = pre[u];
    edge[v].flow -= minflow[t];      //正向变剩余流量减少
    edge[v ^ 1].flow += minflow[t];  //反向边加上
    u = edge[v ^ 1].to;              //
  }
  ans += minflow[t];  //累积答案
}

signed main() {
  std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>T;
int Case=0;
  while (T--) {

    Case++;
    cout<<"Case "<<Case<<": ";
    cin >> n >> m;
    tot = 1;//*
    memset(flag, 0, sizeof flag);
    memset(head, -1, sizeof head);  
    memset(minflow, 0x3f, sizeof minflow);
    memset(edge,0,sizeof edge);
    memset(vis,0,sizeof vis);
    memset(pre,0,sizeof pre);
    ans = 0;
    for (int i = 1; i <= m; i++) {
      cin >> u >> v >> w;
      if (flag[u][v] == 0) {  //处理重边 否则易tle
        add(u, v, w);
        flag[u][v] = tot;  //
      } else {
        edge[flag[u][v] - 1].flow += w;  //正向边 +
      }
    }
    while (bfs(1, n)) {
      update(1, n);
    }

    cout << ans << endl;
  }
  return 0;
}
