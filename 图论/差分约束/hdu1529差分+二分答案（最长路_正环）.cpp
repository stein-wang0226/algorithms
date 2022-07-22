#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//一定要细   （正环）（加边细节）
//题意:一个超市在第i小时中工作的员工数目不能少于req[i]个。有n个应聘的人，第i个人愿意从t{i}开始工作8小时，问最少需要聘请多少人才能使得达到要求。
// 思路  ：假设在前i个时刻设置了s[i]个员工  则有  s[i]-s[i-8]>=r[i](24>=i>=8)
//                                             s[24]-s[i+16]+s[i]>=R[i](0<i<=8)
//我们设在ｉ这个时间开始的员工量为a[i]
//0<=s[i]-s[i-1]<=a[i] 
//  s[24]为答案  二分求     最长路是否存在
const int N = 25;
const int M = 1e4 + 5;
const int inf = 0x3f3f3f3f;
int n, R[N], t,a[N], s[N];                // vis标记入队
int head[N], vis[N], dis[N], tot, neg[N];  //判断  每个点松弛次数不超过n-1
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
int spfa(int s) {  //最长路
  for (int i = 0; i <= 25; i++) dis[i] = -inf;
  dis[s] = 0;
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = 0;
     neg[u]++;
    if(neg[u]>=24)return 0;//判断正环
    for (int i = head[u]; ~i; i = edge[i].next) {
      int v = edge[i].to;
      int dist = edge[i].w;
      if (dis[v] < dis[u] + dist) {  //松弛操作
        dis[v] = dis[u] + dist;
        if (!vis[v]) {  //只要不在队中就入队     可能多次
          vis[v] = 1;
          que.push(v);

        }
      }
    }
  }
  return 1;
}

int check(int mid) {
    init();
    for(int i=1;i<=24;i++){//
      add(i,i-1,-a[i]);
      add(i-1,i,0);
    }
  for (int i = 8; i <= 24; i++) 
  add(i - 8, i, R[i]);
for (int i = 1; i <= 7; i++) {
  add(i+16,i,R[i]-mid);
}
add(0,24,mid);
add(24,0,-mid);//   s[24]=mid;
int ans=spfa(0);
return ans;
}
int T;
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>T;
  while (T--) {
    memset(R,0,sizeof R);
    for (int i = 1; i <= 24; i++) {
      cin >>R[i];
    }
    cin >> n;
    memset(a,0,sizeof a);
    for (int i = 1; i <=n; i++) {
      cin >> t;
      a[t+1]++;//
    }

    int l = 0, r = n+1;
    while (l < r) {  //最小值
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    if(r>=n) puts("No Solution");
    else cout<<r<<endl;
  }
    return 0;
  }
