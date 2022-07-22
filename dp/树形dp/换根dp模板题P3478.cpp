#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
// 换根dp    O(n^2)->O(n)
// 给一颗n个结点的树需要找到以x点为根结点的树，使得所有点的深度和最大
// dp[i]先表示已i为根的树深度和
//先一次dfs 求得dp[1] 默认1为初始根 size[i]为以1为根时子树大小
// 转移 dp[v]=dp[u]-size[v]+（n-size[v]）=dp[u]+n-2*size[v];
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;

int T, n, a[N],dp[N],fa[N];
int sum1;//dp[1]的值
int size[N];
int head[N],tot;
struct Edge{
    int u,v,from,next;
}edge[N*2];

void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u]=tot;
}


void dfs1(int u,int fa,int dep){// 
    sum1+=dep;
    size[u]=1;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa)continue;
        dfs1(v,u,dep+1);
        size[u]+=size[v];   // 同时求此时子树size
    }
}
void dfs2(int u,int fa){  //树形dp
     for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa)continue;
        dp[v]=dp[u]+n-2*size[v];
        dfs2(v,u);
    }

}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
cin>>n;
int u,v;
memset(head,-1,sizeof head);
tot=0;
for(int i=1;i<=n-1;i++){
    cin>>u>>v;
    add(u,v);
    add(v,u);
}
sum1=0;
dfs1(1,0,0);
dp[1]=sum1;
dfs2(1,0);
int maxx=0;
int ans=0;
for(int i=1;i<=n;i++){
if(dp[i]>maxx){
    maxx=dp[i];
    ans=i;
}
}
cout<<ans<<endl;

  return 0;
}
