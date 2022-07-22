#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int num;
//#define int long long
// dinic
//每个机器每台只能执行一个任务，每个任务在同一时段也只能被一台机执行。 给每个任务的开始时间和截止时间，和持续天数。最多给500天。
 
//建立超级源点，源点到每个任务的流量为持续时间，每天到超级汇点的流量为M，这样能限制流量，即每天只能只能有M机器工作，然后每个任务到日期内的每一天设置流量为1，限制流量，即每天这个任务最多被一台机器干

int T;
const int inf = 0x3f3f3f3f;
const int MAXN = 2005;   // DIAN
const int MAXM = 500005;  // BIAN
int n, m, s, t, u, v;
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
  for (int i = 0; i <= num; i++)
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
int Case=0;
cin>>T;
while(T--){
  printf("Case %d: ",++Case);
  memset(head, -1, sizeof head);
  memset(edge, 0, sizeof edge);
tot=1;
ans=0;
int Sum=0;
cin>>n>>m;//n个任务  m台机器  共2+n+500个点
//S=1 任务2~n+1   天n+2~n+501 T=n+502
//第 i个任务 i+1号，第i天 n+1+i号
num=n+502;
s=1;t=n+502;
for(int i=1;i<=n;i++){
  int si,pi,ei;
  cin>>pi>>si>>ei;
    Sum+=pi;
  add(1,1+i,pi);
  for(int j=si;j<=ei;j++){
    add(i+1,n+1+j,1);
  }
}

for(int i=n+2;i<=n+501;i++){
  add(i,t,m);
}



while(bfs(s,t)){
  ans+=dfs(s,inf);
}
//cout<<ans<<endl;
if(ans==Sum)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
cout<<endl;
}
  return 0;
}
