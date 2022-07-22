#include <bits/stdc++.h>
//#define int long long
using namespace std;
//dis(a,b)=dis(a,根)+dis(b,根)-2*dis( lca(a,b) , 根) 
const int N=8e4+5;


int T,n,m,tot,head[N];
int dep[N],fa[N],size[N];//子树大小
int dis[N];
int son[N];  //重儿子
int top[N] ;  // 重链顶端
int in[N]; //入度  根
struct Edge{int from;int to;int w;int next;}edge[2*N];
void add(int u,int v,int w ){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].w=w;
    head[u]=tot;
}
void dfs1(int u,int father){//双向边
    size[u]=1;//初始大小为1
    dep[u]=dep[father]+1;  // 深度
    son[u]=0; fa[u]=father;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        int w=edge[i].w;
        if(v==father)continue; //  向上连的边跳过
       dis[v]=dis[u]+w;   //
        dfs1(v,u);   //  递归搜索子树
        size[u]+=size[v];   //更新size
        if(size[son[u]]<size[v])   son[u]=v; // 寻找更新重儿子 
    }
}
void dfs2(int u,int top_u){  // 更新top
    top[u]=top_u;
    if(son[u]!=0)dfs2(son[u],top_u);// 存在子树  向下更新
    for(int i=head[u];~i;i=edge[i].next){    
        int t=edge[i].to;
        if(t!=fa[u]&&t!=son[u])   //  轻儿子
        dfs2(t,t);           // 开启新的重链
    }
}

//求x,y 的lca  找x,y的lca的重链
//如果 x,y 在同一条重链 那么LCA 就是深度小的点
//  否则将top深度大的点往上跳到top的父亲  这一步跳过一条轻边 到另一条重链
int lca(int x,int y){
        while(top[x]!=top[y]){//不在同一条重链
            if(dep[top[x]]<dep[top[y]])swap(x,y);  ///让x深度大
         x=fa[top[x]];   //x 跳到top的父亲 跳过一条轻边
        }
        //  跳出后    在一条重链
        return dep[x]<dep[y] ? x:y;   // lca为深度小的点  
}


signed main(){


cin>>T;

while(T--){
    cin>>n>>m;
    memset(head,-1,sizeof head);
    memset(in,0,sizeof in);
    memset(dep,0,sizeof dep);
    memset(size,0,sizeof size);
    memset(dis,0,sizeof dis);
    tot=0;
    int u,v,w;
    for(int i=1;i<=n-1;i++){
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=m;i++){
            cin>>u>>v;
            int r=lca(u,v);
            int ans=dis[u]+dis[v]-2*dis[r];
        cout<<ans<<endl;
    }
}

    return 0;
}
