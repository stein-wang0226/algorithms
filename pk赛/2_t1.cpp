#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e6 + 5;
int T, n, a[N],b[N];
int out[N];
struct Edge{
    int to,next;
}edge[N*2];
int m[N];//子树结点最大值
int tot,head[N];
int vis[N];
void add(int u,int v){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
int ans;
int dfs1(int u,int fa){
    m[u]=a[u];
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        m[u]=max(m[u],dfs1(v,u));
    }
    return m[u];
}
void dfs2(int u,int fa,int mx){
    int maxx=0;
    int id=0;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        if(m[v]>maxx){maxx=m[v];id=v;}
    }
    mx=max(mx,maxx);
     for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        if(v==id){ // 如果是最大则保持mx
            dfs2(v,u,mx);
        }
        else dfs2(v,u,m[v]); //否则重开一条链
    }
    if(out[u]==0)ans+=mx;
}
void solve(){
    cin>>n;
    tot=0;
    memset(head,-1,sizeof head);
    ans=0;
    for(int i=1;i<=n;i++)cin>>a[i]; //点权

    for(int i=1;i<=n;i++){
        cin>>b[i];
        add(i,b[i]),add(b[i],i),out[b[i]]++;
    }
dfs1(0,-1);
dfs2(0,-1, 0);
cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}
