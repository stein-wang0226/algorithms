#include <bits/stdc++.h>
#define LOCAL
//define int long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
int dfn[N],low[N],head[N],id[N];//low 孩子最早祖先  dfn 时间戳
int tot,scc_cnt,dfs_clock;
stack<int>S;

struct Edge{
    int from,to,next,w;
}edge[M];
void add(int u,int v,int w){
    edge[++tot].to=v;
    edge[tot].from=u;//可省
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++dfs_clock;//时间戳
    S.push(u);
    for(int i=head[u];~i;i=edge[i].next){//递归遍历子节点
        int v=edge[i].to;
        if(!dfn[v]){//未访问
          tarjan(v);
         low[u]=min(low[u],low[v]);//更新low[u]
        }else if(!id[v]){//已访问 未生成scc
        low[u]=min(low[u],dfn[v]);//反向边更新
        }
    }

if(low[u]==dfn[u]){//存在scc
    scc_cnt++;
    int x;
    do{
        x=S.top();S.pop();
        id[x]=scc_cnt;// 编号
    }while(x!=u);
}
}
void init(){
scc_cnt=dfs_clock=tot=0;//
memset(head,-1,sizeof head);
memset(id,0,sizeof id);
memset(dfn,0,sizeof dfn);
}
int m,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

while(cin>>m>>n){
init();
for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    add(a,b,0);
}

for(int i=1;i<=n;i++){
    if(!dfn[i])tarjan(i);
}



}

    return 0;
}
