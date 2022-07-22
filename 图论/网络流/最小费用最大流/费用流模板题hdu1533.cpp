#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//在n*m的矩阵格子里有x个人（'m'）要走到x个房间（'H'）里，每个房间里只能放一人，人在目前所在的格子处向上下左右相邻的格子走一步就花费1美元，问最后全部的人走到房间后最小的花费。
//最小费用最大流
// s-> 每个人（1，0）    每个人-》每间房（1，最短路径dis）  每间房-》t（1，0）
int T;
const int inf = 0x3f3f3f3f;
const int MAXN = 50005;                    // DIAN
const int MAXM = 500005;                 // BIAN
int n, m, s, t, u, v, c, tot = 1;        //边序号从2开始  (0~1),  2~3  4~5
int w, maxflow, mincost, minflow[MAXN];  //每次起点到i可以增加的流量***
int vis[MAXN], pre[MAXN];                //记录前驱边
int dis[MAXN];                           // 距离（最短路）
int head[MAXN];                          //链式前向星  点i对应起始边
// int flag[MAXN][MAXN];              //标记点对应边编号  处理重边
struct EDGE {
  int to, next;
  int flow;         //剩余流量
  int cost;         //费用
} edge[MAXM << 1];  //反向边双倍

void add(int u, int v, int w, int c) {  //同时加正反两条边
  edge[++tot].to = v;
  edge[tot].flow = w;
  edge[tot].cost = c;
  edge[tot].next = head[u];
  head[u] = tot;
  edge[++tot].to = u;
  edge[tot].flow = 0;  //反向弧初始化为0
  edge[tot].next = head[v];
  edge[tot].cost = -c;  //取反  用于反悔
  head[v] = tot;
}

int spfa(int s, int t) {
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  dis[s] = 0;
  vis[s] = 1;  //入队
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();   //可能重复访问（权值<0）
    vis[u] = 0;  //出队
    for (int i = head[u]; ~i; i = edge[i].next) {
      if (edge[i].flow <= 0) continue;  //没有剩余流量
      int v = edge[i].to;
      if (dis[v] > dis[u] + edge[i].cost) {  //松弛操作
        dis[v] = dis[u] + edge[i].cost;
        minflow[v] = min(minflow[u], edge[i].flow);  //更新最小流量
        pre[v] = i;
        if (!vis[v]) {
          vis[v] = 1;
          que.push(v);
        }  //入队
      }
    }
  }
  if (dis[t] == inf) return 0;
  return 1;
}

void update(int s, int t) {  // EK增广操作， 答案加上
  int u = t;
  maxflow += minflow[t];
  mincost += dis[t] * minflow[t];
  while (u != s) {  //从t->s 通过pre[]  遍历路径  更新
    int v = pre[u];
    edge[v].flow -= minflow[t];      //正向变剩余流量减少
    edge[v ^ 1].flow += minflow[t];  //反向边加上
    u = edge[v ^ 1].to;              //前一条边
  }
}

int N, M;
char Map[105][105];
struct node {
  int x;
  int y;
} man[10005], house[100005];
void init() {
  memset(head, -1, sizeof head);
  memset(minflow, 0x3f, sizeof minflow);
  memset(edge, 0, sizeof edge);
  memset(vis, 0, sizeof vis);
  memset(pre, 0, sizeof pre);
  memset(man, 0, sizeof man);
  memset(house, 0, sizeof house);
  tot = 1;
}
signed main() {
  std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);

#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  while (cin >> N >> M, M + N) {
    maxflow = 0;
    mincost = 0;
    init();
    int cnt1 = 0, cnt2 = 0;  //人数  房子数
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cin >> Map[i][j];
         if (Map[i][j] == '.') continue;
        if (Map[i][j] == 'm') {
          man[++cnt1].x = i;
          man[cnt1].y = j;
        }
        if (Map[i][j] == 'H') {
          house[++cnt2].x = i;
          house[cnt2].y = j;
        }
      }
    }
s=1;t=cnt1+cnt2+2;
for(int i=1;i<=cnt1;i++){
	add(s,i+1,1,0);
}
for(int i=1;i<=cnt2;i++){
	add(cnt1+1+i,t,1,0);
}
for(int i=1;i<=cnt1;i++){
	for(int j=1;j<=cnt2;j++){
		int dis=abs(man[i].x-house[j].x)+abs(man[i].y-house[j].y);
		add(1+i,cnt1+1+j,1,dis);
	}
}
    while (spfa(s, t)) {
      update(s, t);
    }

    cout <<  mincost << endl;
  }
  return 0;
}
