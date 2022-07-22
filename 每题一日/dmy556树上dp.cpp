#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
# pragma GCC optimize(3) 
//#define int long long
using namespace std;
// 每个结点维护递增最长链和递减最长链
const int N=5e5+5;
int T,n,a[N],ans;
int dp1[N],dp2[N];

struct Edge{
  int from,to,next;
}edge[N * 2];
int head[N],tot;
void add(int u,int v){
  edge[++tot].from=u;
  edge[tot].to=v;
  edge[tot].next=head[u];
  head[u]=tot;
}
void dfs(int u,int fa){
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].to;
    if(v==fa)continue;
    dfs(v,u);
    if(a[u]==(a[v]+1)%3)dp1[u]=max(dp1[u],dp1[v]+1);  //递增
    if(a[v]==(a[u]+1)%3)dp2[u]=max(dp2[u],dp2[v]+1);
  }
ans=max(dp1[u]+dp2[u]+1,ans);
}
signed main(){

#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

scanf("%d",&n);
ans=0;
memset(head,-1,sizeof head);
int u,v;
for(int i=1;i<n;i++){
  scanf("%d%d",&u,&v);
  add(u,v);
  add(v,u);
}
for(int i=1;i<=n;i++)scanf("%d",&a[i]);
dfs(1,0);
cout<<ans<<endl;
    return 0;
}
