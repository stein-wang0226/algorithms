#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
#define int long long
using namespace std;

const int N = 2e5 + 5;
int T, n;
int head[N], tot,size[N];
struct Edge {
  int from, to, w, next;
} edge[N * 2];
void add(int u, int v, int w) {
  edge[++tot].from = u;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot;
}
int ans;
//首先发现任意不在相同链上的三点满足
//所以问题转化为求不在同一条路径上的三个结点总数
//考虑任意一个结点的所有子树中选三个子树的结点都满足，当然子树内部也要递归计算
//所以树上dfs求即可
//优化：枚举子树是O(n^3)   但发现两颗子树固定后剩下所有子树的所有结点都算上
//枚举方式： 先遍历固定中间的点J， 再枚举之前的点i 则剩下点数可表示为
//n-sum(a(i~j))
// 那么记录之前枚举过的子树大小之和 sum(i)=m  则每次+   aj*m*(n-m-aj-1)
void dfs(int u, int fa) {
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if(v!=fa){
      dfs(v,u);  // 递归分治
      ans+=size[u]*size[v]*(n-size[v]-size[u]-1); //-1 lca
      size[u]+=size[v];   //size[u]表示之前遍历过的u子树和
    }
  }
size[u]++;//根
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n;
  ans=0;
  memset(head, -1, sizeof head);
    memset(size, 0, sizeof size);
  int u, v, w;
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
      dfs(1, -1);
  cout<<ans<<endl;
  return 0;
}
