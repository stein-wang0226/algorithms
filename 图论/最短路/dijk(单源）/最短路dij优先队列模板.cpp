#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int inf =0x3f3f3f3f;
const int N=1e5+5;
const int M=2e5+5;
int m,n,s,tot;
int head[N],vis[N],dis[N];

struct Edge{
  int from,to,w,next;
}edge[M];
void add(int u,int v,int w){
  edge[++tot].to =v;
  edge[tot].from =u;
  edge[tot].w=w;
  edge[tot].next =head[u];
  head[u]=tot;
}
struct node{// 点  用于 优先队列
int w,id;
bool operator < (const node &b)const{  //小顶堆
  return w>b.w;}
};


void dij(int s){
priority_queue<node>que;
dis[s]=0;
que.push({0,s});
while(!que.empty()){
  node u=que.top();que.pop();
  int cur=u.id;//当前点序号
  if(vis[cur])continue;// 只入队一次 
  vis[cur]=1;
  for(int i=head[cur];~i;i=edge[i].next){
      int v=edge[i].to;
      int dist=edge[i].w;
      if(dis[v]>dis[cur]+dist){
        dis[v]=dis[cur]+dist;
        que.push({dis[v],v});
      }
  }
}
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m>>s;
tot=0;
memset(dis,0x3f,sizeof dis);
memset(vis,0,sizeof vis);
memset(head,-1,sizeof head);
for(int i=1;i<=m;i++){
  int u,v,c;
  cin>>u>>v>>c;
  add(u,v,c);
}
dij(s);
for(int i=1;i<n;i++)cout<<dis[i]<<" ";cout<<dis[n]<<endl;
    return 0;
}
