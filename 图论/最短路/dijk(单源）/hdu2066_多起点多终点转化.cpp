#include <bits/stdc++.h>
#define LOCAL
using namespace std;
set<int>St;
int N=0;//统计城市数
//多起点，终点的dijkstra
//起点城市前加虚拟点，权值为0
//终点也加，之后只需求虚拟起点到虚拟终点
const int inf=0x3f3f3f3f;
int m,n,k,Map[1005][1005],dis[1005],vis[1005],S,T;
void dijkstra(){
    dis[S]=0;
    vis[S]=1;
      while(S!=T){//从小到大找最短路，直到找到T就无需继续
        int Min=inf;
        int next;
        for(int i=0;i<=1001;i++){//**每次从当前起点找相对其的最短路
            if(Map[S][i]!=inf)//存在道路
            dis[i]=min(dis[i],Map[S][i]+dis[S]);//**对每个相连点松弛操作
            
            if(!vis[i]&&dis[i]<Min){//更新当前最短路
                        next=i;
                        Min=dis[i];   
            }
         }   
                if(Min==inf)  break;//之后都没有道路，跳出
                S=next;//更新起点以做下一个松弛操作
                vis[S]=1;//标记已生成过
         }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>m>>n>>k){
    memset(Map,0x3f,sizeof Map);
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    St.clear();
    N=2;
    S=0;//虚拟起点
    T=1001;
    for(int i=1;i<=m;i++){
        int a,b,dist;
        cin>>a>>b>>dist;
        if(!St.count(a)){St.insert(a);N++;}
        if(!St.count(b)){St.insert(b);N++;}
        Map[a][b]=min(dist,Map[a][b]);
        Map[b][a]=Map[a][b];
    }
    for(int i=1;i<=n;i++){
       int start;
        cin>>start;
        Map[start][S]=Map[S][start]=0;//虚拟起点 到各起点距离为0
    }
     for(int i=1;i<=k;i++){//虚拟终点到各终点距离为0；
       int End;
        cin>>End;
        Map[End][T]=Map[T][End]=0;
    }
    dijkstra();

    cout<<dis[T]<<endl;

}
    return 0;
}
