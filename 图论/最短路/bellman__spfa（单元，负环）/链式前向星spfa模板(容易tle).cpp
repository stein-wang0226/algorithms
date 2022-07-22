#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//dij的队列优化
#define maxn 100005
#define maxm 200005
#define inf  0x3f3f3f3f
struct edge{
    int to,w,next;
}Edge[maxm];
int head[maxn];//存储该起点的最后一条边位置
int dis[maxn],vis[maxn],m,n,s,cnt;

void add(int u,int v,int w ){//链式前向星
    Edge[++cnt].to=v;//下标从零开始
    Edge[cnt].w=w;
    Edge[cnt].next=head[u];//该点的的邻边（上一条输入的边）
    head[u]=cnt;
    //更新目前该点的最后一条边位置（就是当前输入的边）
}

queue<int>q;
void spfa(){//队列优化:只将进行过松弛的有效点入队
dis[s]=0;//第一个弹出
 //赋初值
q.push(s);//起始点
vis[s]=1;
while(!q.empty()){//直到所有点都更新
   int u=q.front();
   q.pop();
    vis[u]=0;//出队
    for(int i=head[u];i;i=Edge[i].next){//寻找与u相连的边
        //相对与普通bellman遍历所有n-1个点，只需遍历u相邻的有效点
      //因为只有与u相邻的v才可能通过dis[u]和w(u-v距离)松弛dis[v]
       int v=Edge[i].to;//相连的点
    dis[v]=min(dis[v],dis[u]+Edge[i].w);
   if(!vis[v])vis[v]=1,q.push(v);//未入队则入队
   }

}
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m>>s;//s为起点
cnt=0;
memset(dis,0x3f,sizeof dis);
for(int i=1;i<=m;i++){
    int u,v,c;
    cin>>u>>v>>c;
    add(u,v,c);
}
spfa();
for(int i=1;i<=n;i++){
   // if(dis[i]==inf)cout<<ret<<" ";
    //else
     cout<<dis[i]<<" ";
}
    return 0;
}
