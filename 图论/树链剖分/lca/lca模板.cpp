#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
int T,n,tot,head[N];
int dep[N],fa[N],size[N];//子树大小
int son[N];  //重儿子
int top[N] ;  // 重链顶端
struct Edge{int from;int to;int w;int next;}edge[2*N];
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs1(int u,int father){
    size[u]=1;;//初始大小为1
    dep[u]=dep[father]+1;  // 深度
    son[u]=0; fa[u]=father;
    for(int i=head[u];~i;i=edge[i].next){
        int t=edge[i].to;
        if(t==father)continue; //  向上连的边跳过
        dfs1(t,u);   //  递归搜索子树
        size[u]+=size[t];   //更新size
        if(size[son[u]]<size[t])   son[u]=t; // 寻找更新重儿子 
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
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

    return 0;
}
