#include <bits/stdc++.h>
#define LOCAL
#define int long long
//预处理根所有节点异或和(前缀)
// lca   两个区间异或起来即可
//  异或前缀和性质  **交换律 逆运算
using namespace std;
const int N=2e6+100;
int T,n,m;
int tot,head[N];
int dep[N],fa[N],size[N];//子树大小
int son[N];  //重儿子
int top[N] ;  // 重链顶端
struct Edge{int from;int to;int w;int next;}edge[4*N];
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs1(int u,int father){// 假设1的fa为0
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
        return dep[x]<dep[y] ? x:y;   // lca为深度小的点  
}

int v[N],sum[N]; // 点权  到根的前缀
void dfs(int u,int res){ //正向dfs
res=res^v[u];
sum[u]=res;
for(int i=head[u];~i;i=edge[i].next){
  int v=edge[i].to;
  if(v!=fa[u])dfs(v,res);
}
}

signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
memset(head,-1,sizeof head);
for(int i=1;i<=n;i++)cin>>v[i];
memset(head,-1,sizeof head);
for(int i=1;i<=n-1;i++){
  int u,v;
  cin>>u>>v;
  add(u,v,0);
  add(v,u,0);
}
// 求根的前缀异或和
dep[0]=0;
dfs1(1,0);
dfs(1,0);   //无向图 假设1为根 
dfs2(1,1);

for(int i=1;i<=m;i++){
  int u,v;
  cin>>u>>v;
  int r=lca(u,v);
  int ans=sum[u]^sum[r]^sum[v]^sum[fa[r]];  //区间和
  printf("%ld\n",ans);
}
    return 0;
}