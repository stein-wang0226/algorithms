#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
const int inf =110000;  // 不能开太大
using namespace std;
// 题目大意：有n个士兵，编号从1到n，它们组成一棵树，且编号1是指挥官，叶子节点的士兵是前线士兵，现在要你切断所有前线士兵与指挥官的通信，也就是删掉一些边
// 其中每条边都有一个代价，删除一条边就要耗费相应代价。现在要你求总代价不超过m，使单条边最大代价最小，求这个最小值。
// 显然二分
//dp [i]  表示i与所有叶子断开的最小值  要么是子树自己断开了  要么是与子树连的边断开了 所以转移：dp(i) = ∑min(dp(son),e[i].w)
const int N = 2e3 + 5;
int T, n, m, a[N];
int dp[N];
struct Edge {
  int from, to, next, w;
} edge[2 * N];
int head[N], tot;
void add(int u, int v, int w) {
  edge[++tot].from = u;
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot;
}
void dfs(int u,int fa,int x){
    int is_leaf=1;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        is_leaf=0;   // 不是叶子
        dfs(v,u,x);// 先递归到叶子
    }
        if(is_leaf)dp[u]=inf;   // 叶子初始化为无穷（不合法）  （没有子树可连接）  只能切断相连边
        for(int i=head[u];i;i=edge[i].next)
        {         
        int v=edge[i].to;
        if(v==fa)continue;
        if(edge[i].w>x)dp[u]+=dp[v];//  这条边大于x 不能删
        else dp[u]+=min(dp[v],edge[i].w);
        }   // 子树自身已断开  或断与子树相连的边
}
int check(int x){//删除的所有边小于x，
    memset(dp, 0, sizeof(dp)); 
    dfs(1, 0, x); 
    return dp[1] <= m;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n >> m, m || n) {
    memset(head, 0, sizeof head);
    tot = 0;
    int u, v, w;
    for (int i = 1; i< n; i++) {
      cin >> u >> v >> w;
      add(u, v, w);
      add(v, u, w);
    }
    int l=0,r=1e9;
    int ans=-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid,ans=r;
        else l=mid+1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
