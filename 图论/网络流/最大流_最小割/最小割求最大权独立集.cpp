#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//最大权独立集 ==总权值-最小割(简单割)
//将格子按奇偶星染成黑白两色 -->二分图 (拆点也可) 连相邻边 ， 求最大权独立集即可
//#define int long long
// dinic
const int inf = 0x3f3f3f3f;
const int MAXN = 2005;
const int MAXM = 200005;
int n, m, s, t, u, v;
int tot;
int w, ans, dep[MAXN];
int head[MAXN];
int cur[MAXN];

struct EDGE {
  int to, next;
  int flow;
} edge[MAXM << 1];

void add(int u, int v, int w) {
  edge[++tot].to = v;
  edge[tot].flow = w;
  edge[tot].next = head[u];
  head[u] = tot;

  edge[++tot].to = u;
  edge[tot].flow = 0;
  edge[tot].next = head[v];
  head[v] = tot;
}

int bfs(int s, int t) {  // bfs
  for (int i = 0; i <= t; i++) dep[i] = inf, cur[i] = head[i];
  queue<int> que;
  que.push(s);
  dep[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = head[u]; ~i; i = edge[i].next) {
      if (edge[i].flow == 0) continue;
      int v = edge[i].to;
      if (edge[i].flow > 0 && dep[v] == inf) {
        que.push(v);
        dep[v] = dep[u] + 1;
        if (v == t) return 1;
      }
    }
  }
  return 0;
}
int dfs(int u, int sum) {
  if (u == t) return sum;
  int k, res = 0;
  for (int i = cur[u]; (~i) && sum; i = edge[i].next) {
    cur[u] = i;  //
    int v = edge[i].to;
    if (edge[i].flow > 0 && (dep[v] == dep[u] + 1)) {
      k = dfs(v, min(sum, edge[i].flow));
      if (k == 0) dep[v] = inf;
      edge[i].flow -= k;
      edge[i ^ 1].flow += k;
      res += k;  //
      sum -= k;  //
    }
  }
  return res;
}

int N, Map[105][105];
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> N) {
    memset(head, -1, sizeof head);
    memset(edge, 0, sizeof edge);
    memset(Map, 0, sizeof Map);
    tot = 1;
    int Sum = 0;
    int cnt = 0;
    ans = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        cin >> Map[i][j];
        Sum += Map[i][j];
      }
    }
    s = 1, t = N * N + 2;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
         if ((i+j)&1) add(N*(i-1)+j+1,N*N+2,Map[i][j]);
                 else{// 相邻连边
                    add(1,N*(i-1)+j+1,Map[i][j]);
                    if (i>1) add(N*(i-1)+j+1,N*(i-2)+j+1,inf);
                    if (i<N) add(N*(i-1)+j+1,N*i+j+1,inf);
                    if (j>1) add(N*(i-1)+j+1,N*(i-1)+j,inf);
                    if (j<N) add(N*(i-1)+j+1,N*(i-1)+j+2,inf);
                 }

    while (bfs(s, t)) {
      ans += dfs(s, inf);
    }

    cout << Sum - ans << endl;
  }
  return 0;
}
