#include <bits/stdc++.h>
//#define LOCAL
using namespace std;
//#define int long long
// dinic
// 和机器分配相同  要离散化时间区间
int T;
const int inf = 0x3f3f3f3f;
const int MAXN = 20005;   // DIAN
const int MAXM = 50005;  // BIAN
int n,  s, t, u, v;     
int tot;  
int w, ans, dep[MAXN];  
int head[MAXN];     
int cur[MAXN];         

struct EDGE {
  int to, next;
  int flow;         
} edge[MAXM << 1];  

void add(int u, int v,
         int w) {  
  edge[++tot].to = v;
  edge[tot].flow = w;
  edge[tot].next = head[u];
  head[u] = tot;

  edge[++tot].to = u;
  edge[tot].flow = 0;  
  edge[tot].next = head[v];
  head[v] = tot;
}

int bfs(
    int s,
    int t) {  // bfs

  for (int i = 0; i <= t; i++) dep[i] = inf,cur[i] = head[i];     
  queue<int> que;     
  que.push(s);
  dep[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; ~i; i = edge[i].next) { 
      if (edge[i].flow == 0)
        continue;  //已处理完
      int v = edge[i].to;
      if (edge[i].flow > 0 &&//
          dep[v] ==
              inf) {  
        que.push(v);
        dep[v] = dep[u] + 1;  //分层
        if (v == t)
          return 1;  
      }
    }
  }
  return 0;
}

int dfs(
    int u,
    int sum) {  
  if (u == t) return sum;
  int k, res = 0;  
  for (int i = cur[u]; (~i) && sum;
       i = edge[i].next) {  
    cur[u] = i;  //当前弧优化
    int v = edge[i].to;
    if (edge[i].flow > 0 &&
        (dep[v] ==
         dep[u] + 1)) {  
      k = dfs(v, min(sum, edge[i].flow));  //
      if (k == 0)
        dep[v] = inf;  
      edge[i].flow -= k;
      edge[i ^ 1].flow += k;     
      res += k;  // 增广流量
      sum -= k;  // 该结点剩余流量
    }
  }
  return res;
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int M, N;
  while (cin >> N >> M) {
    memset(head, -1, sizeof head);
    memset(edge, 0, sizeof edge);
    tot = 1;
    ans = 0;
    int si[20005], ni[20005], e[20005], ti[20005], time[100005];
    int cnt = 0;
    int Sum = 0;  //满流
    memset(time, 0, sizeof time);
    for (int i = 1; i <= N; i++) {
      cin >> si[i] >> ni[i] >> e[i] >> ti[i];
      time[++cnt] = si[i];
      time[++cnt] = e[i];
      Sum += ni[i] * ti[i];
    }
    //离散化
    sort(time + 1, time + 1 + cnt);
    int len =
        unique(time + 1, time + 1 + cnt) - (time + 1);  //***  去重 后时间点数
    s = 1;
    t = 1 + N + len;
    for (int i = 1; i <= N; i++) {
      add(s, i + 1, ni[i] * ti[i]);
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j < len; j++) {  //每个人变量遍历所有区间time[j]~time[j+1]
        if (si[i] <= time[j] && e[i] >= time[j + 1]) {
          add(i + 1, N + 1 + j, inf);
        }
      }
    }

    for (int i = 1; i < len; i++) {
      add(i + N + 1, t, (time[i+1]-time[i])*M);  //  要乘时间点数
    }
    while (bfs(s, t)) {
      ans += dfs(s, inf);
    }
  // cout<<ans<<" "<<Sum;
    if (ans == Sum)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}