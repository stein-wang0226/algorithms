#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int inf=0x3f3f3f3f;
//还是最经典的dijkstra算法，记录距离的同时记录一下花费就行。最后按距离优先输出const int inf=0x3f3f3f3f;
//在松弛操作时--当距离相同更新花费
int m,n,Map1[1005][1005],Map2[1005][1005],dis[1005],cost[1005],vis[1005],S,T;
int main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m,n+m){
    memset(Map1,0x3f,sizeof Map1);//初始化正无穷
     memset(Map2,0x3f,sizeof Map2);//初始化正无穷
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++){
        int a,b,dist,c;
        cin>>a>>b>>dist>>c;
        Map1[a][b]=min(dist,Map1[a][b]);
        Map1[b][a]=Map1[a][b];//无向图
        Map2[a][b]=min(c,Map2[a][b]);
        Map2[b][a]=Map2[a][b];//无向图
    }
   cin>>S>>T;
    dis[S]=0;//
    cost[S]=0;
    vis[S]=1;
    while(S!=T){//从小到大找最短路，直到找到T就无需继续
        int Min=inf;
        int next;
        for(int i=1;i<=n;i++){//**每次从当前起点找相对其的最短路
            if(Map1[S][i]!=inf){//存在道路
            if(dis[i]>Map1[S][i]+dis[S]){dis[i]=Map1[S][i]+dis[S];cost[i]=Map2[S][i]+cost[S];}
            
            else if(dis[i]==Map1[S][i]+dis[S]){//距离相同则更新花销***  唯一改动
                if(cost[i]>Map2[S][i]+cost[S])cost[i]=Map2[S][i]+cost[S];
            }
            if(!vis[i]&&dis[i]<Min){//更新当前最短路
                        next=i;
                        Min=dis[i];
            }
              
         }    
         }
                if(Min==inf)  break;//之后都没有道路，跳出
                S=next;//更新起点以做下一个松弛操作
                vis[S]=1;//标记已生成过
        
}
 cout<<dis[T] <<" "<<cost[T]<<endl;
}
    return 0;
}
