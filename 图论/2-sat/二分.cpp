#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//给你n对钥匙，每对只能选一把来用，有m扇门，每扇门有两把钥匙都可以打开，问怎么选钥匙，使开的门最多，
//门得按顺序开（二分的条件）
//分析：两种限制1.同一对只用一把 2.同一扇门只用一把  然后按照这个思路建图就行。。。由于m比较大，所有二分m判断可行性即可
//建图  将开同一扇门的两把看一对重新编号   选 i 后 i ->u' 
//注意 若按原来编号同一串并非都要用到所以不行 
const int N=1<<10+5;
const int MAX=1<<11+5;
int  m,n,dfn[N*2],low[N*2],head[N*2],id[N*2],order[N*2];
int tot ,scc_cnt,dfs_clock;
stack<int>S;
struct Edge{
    int from,to,w,next;
}edge[MAX*28];
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int u){
dfn[u]=low[u]=++dfs_clock;
S.push(u);
for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].to;
    if(!dfn[v]){
        tarjan(v);
        low[u]=min(low[u],low[v]);
    }else if(!id[v]){
        low[u]=min(low[u],dfn[v]);//反向边
    }
}
if(dfn[u]==low[u]){
scc_cnt++;
int x;
do{
    x=S.top();
    S.pop();
    id[x]=scc_cnt;
}while(x!=u);
}
}

int k1[N],k2[N];
void init(){
memset(head,-1,sizeof head);
memset(id,0,sizeof id);
scc_cnt=dfs_clock=0;
memset(dfn,0,sizeof dfn);
memset(low,0,sizeof low);
}
bool check(int mid){
    init();
for(int i=0;i<mid;i++){//前mid扇门 建图
    add(order[k1[i]],order[k2[i]]^1,0);//order[k[i]]  第i扇门的新编号
    add(order[k2[i]],order[k1[i]]^1,0);
}
    
for(int i=0;i<2*n;i++){
    if(!dfn[i])tarjan(i);
}
for(int i=0;i<2*n;i+=2){
    if(id[i]==id[i^1])return 0;
}
return 1;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m,m+n){
    memset(edge,0,sizeof edge);
    memset(order,0,sizeof order);
    memset(k1,0,sizeof k1);
    memset(k2,0,sizeof k2);
for(int i=0;i<n;i++){//每对钥匙
    int a,b;
    cin>>a>>b;
    order[a]=i*2;
    order[b]=i*2+1;//重新编号 第一串->（0，1）
}
for(int i=0;i<m;i++){//每扇门
cin>>k1[i]>>k2[i];
}

int l=0,r=m;//合法最大值  l=mid
while(l<r){
int mid=(l+r+1)/2;
if(check(mid))l=mid;
else r=mid-1;
}
cout<<l<<endl;
}
    return 0;
}
