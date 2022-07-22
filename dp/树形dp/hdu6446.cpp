#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
const int mod=1e9+7;
//给出一个1,2,3...N的排列，显然全部共有N!种排列，每种排列的数字代表树上的一个结点，设Pi是其中第i种排列的相邻数字表示的结点的距离之和，让我们求sum(Pi)(1<=i<=N!)。
//可以设dis(i, j)为树上任意两点间的最短距离，稍加分析一下容易得到所求答案为 (N-1)! * sum(dis(i, j))*2。对于dis(i, j)很容易想到用Floyd算法来求，但题目数据量为1e5很明显复杂度O(n^3)的算法肯定超时。由于这是一棵树，
//dis(i, j)的最短路径是唯一的（不存在环），那么对于相邻结点u, v，可以发现边(u, v)走过的次数为左边结点数量*右边结点数量  (u的子树结点数k)*（n-k）
int T, n, a[N];
int head[N],tot;
struct Edge{
  int from,to,w,next;
}edge[N*2];

void add(int u,int v,int w){
  edge[++tot].from=u;
  edge[tot].to=v;
  edge[tot].w=w;
  edge[tot].next=head[u];
  head[u]=tot;
}
int ans;
int size[N];
void dfs(int u,int fa){
  size[u]=1;
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].to;
    int w=edge[i].w;
    if(v==fa)continue;
    dfs(v,u);
    size[u]+=size[v];
    ans+=size[v]*(n-size[v])*w;
    ans%=mod;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (cin>>n) {
   tot=0;
    memset(head,-1,sizeof head);
      int u,v,w;
      int res=1; // (n-1)!
    for(int i=1;i<=n-1;i++){
      res=res*i%mod;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    ans=0;
    dfs(1,0);
    ans=ans*res*2%mod;
    cout<<ans<<endl;
  }
  return 0;
}
