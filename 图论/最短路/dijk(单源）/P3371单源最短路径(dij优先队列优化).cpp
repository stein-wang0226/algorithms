#include <bits/stdc++.h>
#define LOCAL
#define int long long
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
struct node
{
    int w,now;//权值，点的序号
    bool operator <(const node &x)const
    //小的在前（大根堆）
    {
        return w>x.w;//这里注意符号要为'>'
    }
};
priority_queue<node>q;
void dij(){//队列优化
dis[s]=0;//第一个
 //赋初值
q.push(node{0,s});//起始点
while(!q.empty()){//直到所有点都更新
    node u=q.top();//当前最短路
    q.pop();
    int Now=u.now;//以Now为起点继续更新
    if(vis[Now])continue;//已标记
    vis[Now]=1;
    for(int i=head[Now];i!=0;i=Edge[i].next){//链式前向星遍历Now的所有邻点
    int v=Edge[i].to;
    if(dis[v]>dis[Now]+Edge[i].w){//对所有相邻的松弛操作
        dis[v]=dis[Now]+Edge[i].w;
        //松弛操作
        q.push(node{dis[v],v});//只有松弛过才可能影响之后的路径  入队  
    }
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

dij();
//unsigned long long ret=(1<<31)-1;//由题不存在输出
for(int i=1;i<=n;i++){
   // if(dis[i]==inf)cout<<ret<<" ";
    //else
     cout<<dis[i]<<" ";
}
    return 0;
}
