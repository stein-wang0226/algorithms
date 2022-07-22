#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//#define int long long
// dinic
int T;
const int inf = 0x3f3f3f3f;
const int MAXN = 2005;   // DIAN
const int MAXM = 505000;  // BIAN
int n, m, s, t, u, v;//   变量含义不要误用
int tot;                //边序号从2开始  (0~1),  2~3  4~5
int w, ans, dep[MAXN];  //点的层深度
int head[MAXN];         //链式前向星  点i对应起始边
int cur[MAXN];          //当前弧优化

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

int bfs(int s, int t) {  // bfs  在残量网络中构造分层图
  for (int i = 0; i <= t; i++)//
    dep[i] = inf, cur[i] = head[i];  // dep初始化无穷 同时起标记作用
  queue<int> que;  //  cur 初始化为head   用于之后弧优化
  que.push(s);
  dep[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; ~i; i = edge[i].next) {  //遍历边
      if (edge[i].flow == 0) continue;             //无剩余流量跳过
      int v = edge[i].to;
      if (edge[i].flow > 0 && dep[v] == inf) {  // 有残余流量且为访问
        que.push(v);
        dep[v] = dep[u] + 1;   //记录深度
        if (v == t) return 1;  //跳出  找到一条增广路
      }
    }
  }
  return 0;
}
// 在层次图基础上不断dfs 求得增广路 (多条)
int dfs(int u, int sum) {  // sum表示当前流入可该点的剩余流量
  if (u == t) return sum;
  int k, res = 0;  // k为当前最小剩余容量
  for (int i = cur[u]; (~i) && sum; i = edge[i].next) {  // 弧优化  sum
    cur[u] = i;  //当前弧优化                                       //弧优化
    int v = edge[i].to;
    if (edge[i].flow > 0 && (dep[v] == dep[u] + 1)) {  //有剩余流量  层数差1
      k = dfs(v, min(sum, edge[i].flow));              //  u流入v的流量
      if (k == 0) dep[v] = inf;  //*剪枝， 去掉增广完的点
      edge[i].flow -= k;
      edge[i ^ 1].flow += k;
      res += k;  // res表示经过该点的所有流量和（相当于流出的总量）
      sum -= k;  // sum表示经过该点的剩余流量 (有多个v)
    }
  }
  return res;
}

//拆点
int Case;
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> T;
  int Case=0;

  while (T--) {
    memset(head, -1, sizeof head);
    memset(edge, 0, sizeof edge);
    tot = 1;
    ans = 0;
    int d;
    cin >> n >> d;
    getchar();
    string str;
    char G1[25][25];
    char G2[25][25];
    for (int i = 1; i <= n; i++) {
      cin >> str;
      m = str.size();
      for (int j = 1; j <= m; j++) {
        G1[i][j] = str[j - 1];
      }
    }
        getchar();

    for (int i = 1; i <= n; i++) {
      cin >> str;
      for (int j = 1; j <= m; j++) {
        G2[i][j] = str[j - 1];
      }
    }
    s = 1;
    t = 2 * m * n + 2;
    //入点 2~m*n+1   出点m*n+2~2*mn+1
    //出点又可连回距离小于d的入点
      int Sum=0;//蜥蜴数
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (G2[i][j] == 'L') {add(s, (i - 1) * m+ j + 1, 1);Sum++;}  //有L 连
      }
    }

    
    //建图
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int k = (i - 1) * m + j + 1;
        int kk = k + m * n;
        int v = G1[i][j] - '0';
        if(v)add(k, kk, v);
        if (i <= d || i + d > n || j <= d || j + d > m) {  //可直接跳出
          add(k + m * n, t, inf);
        }
      }
    }
  //反向连回  （跳到别的点）
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if (i <= d || i + d > n || j <= d || j + d > m)continue;
        int k=(i-1)*m+j+1;
      for(int i2=1;i2<=n;i2++){
        for(int j2=1;j2<=m;j2++){
          if(i==i2&&j==j2)continue;//不能跳回自己
          int dis=abs(i-i2)+abs(j-j2);
          if(dis<=d){
            int kk=(i2-1)*m+j2+1;
            add(k+m*n,kk,inf);   
          }
        }
      }
    }
  }

    while (bfs(s, t)) {
      ans += dfs(s, inf);
    }
    ans=Sum-ans;
    
    if(ans==0) printf("Case #%d: no lizard was left behind.\n",++Case);
         else if(ans==1) printf("Case #%d: 1 lizard was left behind.\n",++Case);
         else printf("Case #%d: %d lizards were left behind.\n",++Case,ans);
  }
  return 0;
}
