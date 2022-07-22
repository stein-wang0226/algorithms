#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//772 e  
//给定某两点相关或不相关关系  
//1.方向  不论是否相关 只要存在关系则方向不同
//***  建图 相连两点为不同方向 所以为二分图 染色法判断即可
//2.  位置  设u向左 v向右 uv同向相关有 坐标 (小->大)  u小于v 记v->u    无关则u 大于v  记u->v
//  存在偏序关系 拓扑排序输出位置即可   （不一定连通）
using namespace std;
const int N=2e5+5;
int m,n;
int head[N],tot,color[N],vis[N];
int u[N],v[N],t[N]; //input
int in[N];
struct Edge{
    int from,to,next;
} edge[N*2];//

void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
int dfs(int u,int c){// 将u 染c  dfs   
    color[u]=c;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(color[v]==color[u])return 0;  //矛盾
        if(color[v]==-1&&!dfs(v,1-c))return 0;    // 染成别的 递归dfs 
    }
    return 1;
}
 // col = 0 -> orient left, col = 1 -> orient right
bool is_bit(){
    for(int u=1;u<=n;u++){
        if(color[u]==-1)
        if(!dfs(u,0))return 0;   //对每个连通块 假设染成0 左
    }
    return 1;
}

signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
tot=0;
cin>>n>>m;
memset(head,-1,sizeof head);
memset(color,-1,sizeof color);
for(int i=1;i<=m;i++){
    cin>>t[i]>>u[i]>>v[i];    
    add(u[i],v[i]);add(v[i],u[i]);//  二分图 无向
}

if(!is_bit()){
    puts("No");
    return 0;
}
tot=0;//重新初始化
memset(head,-1,sizeof head);//清空 判断位置
memset(edge,0,sizeof edge);
for(int i=1;i<=m;i++){
    if (color[u[i]] == 1)swap(u[i], v[i]);  //默认1为右   而u为左
    if(t[i]==1)add(u[i],v[i]); // 无关 u<v
    else add(v[i],u[i]);
}
// 拓扑

for(int u=1;u<=n;u++){
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        in[v]++;
    }
}
queue<int>que;
int cnt=0;// topo 序号
int idx[N];//  点 i 的序号
for(int i=1;i<=n;i++){
    if(in[i]==0){
        que.push(i);            
    }
}
while(!que.empty())
{
    int x=que.front();
    que.pop();
    idx[x]=++cnt;
    for(int u=head[x];~u;u=edge[u].next){
        int v=edge[u].to;
        if(--in[v]==0)que.push(v);
    }
}   
if(cnt!=n){
    cout<<"No"<<endl;
    return 0;
}
    cout << "YES" << endl;

 for (int i = 1; i <= n; ++i) {
        cout << (color[i] == 0 ? "L " : "R ") << idx[i] << endl;
    }

 return 0;
}
