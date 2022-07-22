#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
int T,n,tot,head[N];
int dep[N],fa[N],size[N];//子树大小
int son[N];  //重儿子
int top[N] ;  // 重链顶端
int dfn,nid[N],oid[N]; //  新编号用于树上操作
struct Edge{int from;int to;int w;int next;}edge[2*N];
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[u].next=head[u];
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
    nid[u]=++dfn;  //原始元素u 对应的dfs序新编号 是nid[x];
    oid[dfn]=u;    // 新编号nid[x]对应老编号 是x ,
    if(son[u]!=0)dfs2(son[u],top_u);// 存在子树  向下更新
    for(int i=head[u];~i;i=edge[i].next){    
        int t=edge[i].to;
        if(t!=fa[u]&&t!=son[u])   //  轻儿子
        dfs2(t,t);           // 开启新的重链
    }
}  //   如果对 x的整个子树操作，对应区间 [nid[x],nid[x]+size[x]-1]]

//  具体操作可以是各种修改  ，也可以是各种查询
int chian(int x,int y){
        while(top[x]!=top[y]){//不在同一条重链
            if(dep[x]<dep[y])swap(x,y);  ///让x深度大
        x=fa[top[x]];   //x 跳到top的父亲 跳过一条轻边
        }//  跳出后    在一条重链
        if(dep[x]>dep[y])swap(x,y);//  x在上
        //对 [x,y]区间 具体操作 
}

signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

    return 0;
}
