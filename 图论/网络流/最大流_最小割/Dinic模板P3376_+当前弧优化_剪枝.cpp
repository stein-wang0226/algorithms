#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//#define int long longA
// dinic
int T;
const int inf = 0x3f3f3f3f;
const int MAXN = 20005;   // DIAN
const int MAXM = 500005;  // BIAN
int n, m, s, t, u, v;     //ע����Щ�������� 
int tot;                //边序号从2开始  (0~1),  2~3  4~5
int w, ans, dep[MAXN];  //点的层深度
int head[MAXN];         //链式前向星  点i对应起始边
int cur[MAXN];          //当前弧优化
//对于一个节点xx，当它在DFS中走到了第ii条弧时，前i-1条弧到汇点的流一定已经被流满而没有可行的路线了
//那么当下一次再访问xx节点时，前i-1条弧就没有任何意义了
//所以我们可以在每次枚举节点x所连的弧时，改变枚举的起点，这样就可以删除起点以前的所有弧，来达到优化剪枝的效果
//对应到代码中，就是cur数组
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
  for (int i = 0; i <= n; i++)
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
      if (edge[i].flow>0 && dep[v] == inf) {  // 有残余流量且为访问
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
  for (int i = cur[u]; (~i )&& sum; i = edge[i].next) {  // 弧优化  sum
    cur[u] = i; //当前弧优化                                       //弧优化
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

signed main() {

#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  memset(head, -1, sizeof head);
  memset(edge, 0, sizeof edge);
 tot=1;
ans=0;
cin>>n>>m>>s>>t;
for(int i=1;i<=m;i++){
  cin>>u>>v>>w;
  add(u,v,w);
}


while(bfs(s,t)){
  ans+=dfs(s,inf);
}
cout<<ans<<endl;
  return 0;
}
