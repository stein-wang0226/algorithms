#include <bits/stdc++.h>
//#define LOCAL
//define int long long
using namespace std;
const int N=2000000;
const int M=10000005;
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
        }
        else if(!id[v]){//已访问 未生成scc
        low[u]=min(low[u],dfn[v]);//更新
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
int m,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
tot=scc_cnt=0;
memset(edge,0,sizeof edge);
memset(head,-1,sizeof head);
cin>>n>>m;
for(int k=1;k<=m;k++){
    int i,a,j,b;
    cin>>i>>a>>j>>b;//或  
        i --, j -- ;
        add(2 * i + !a, 2 * j + b,0);
        add(2 * j + !b, 2 * i + a,0);
}
for(int i=0;i<2*n;i++){
    if(!dfn[i])tarjan(i);
}

    for (int i = 0; i < n * 2; i ++ )
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i < n; i ++ )
        if (id[i * 2] == id[i * 2 + 1])
        {
            puts("IMPOSSIBLE");
            return 0;
        }
    puts("POSSIBLE");
    for (int i = 0; i < n; i ++ )
        if (id[i * 2] < id[i * 2 + 1]) printf("0 ");
        else printf("1 ");
    return 0;
}
