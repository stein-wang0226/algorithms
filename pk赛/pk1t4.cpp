#include <bits/stdc++.h>
# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;
int T, n,m, a[N];
int read() {
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
struct Edge{
    int to,next;
}edge[N];
int tot,head[N];
int link[N];
bool vis[N];
void add(int u,int v){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}

int dfs(int u){
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(!vis[v]){
           vis[v]=1;
            if(link[v]==-1||dfs(link[v])){
                link[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(){
    int res=0;
    memset(link,-1,sizeof link);
    for(int u=1;u<=m;u++){
       memset(vis,0,sizeof vis);
       // for(int i=m;i<=m+n+5;i++)vis[i]=0;
        if(dfs(u))res++;
        else break; //找不到  跳出   题目要求连续
    }
    return res;
}
void solve(){
    memset(head,-1,sizeof head);
    tot=0;
    n=read(),m=read();  
     int x,y;
    for(int i=1;i<=n;i++){
    x=read(),y=read();  
        //cin>>x>>y;
        add(x,i+m);
        add(y,i+m);
    }
    int ans=hungary();
    cout<<ans<<endl;
}
signed main() {


      solve();
  
  return 0;
}
