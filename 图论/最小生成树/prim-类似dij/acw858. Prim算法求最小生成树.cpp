#include <bits/stdc++.h>
//#define LOCAL
//  最小生成树 朴素prim算法   非常类似dij算法
//每次找集合外离集合最近的点并标记 更新其他点到集合距离
using namespace std;
const int N=510,inf=0x3f3f3f3f;
int n,m;
int G[N][N];  //存原图所有边
int dist[N];   //点到集合的最短距离
bool vis[N];  //标记是否已经在集合
int prim(){
  memset(dist ,0x3f,sizeof dist);
  int res=0;//  最小生成树答案 边长总和
  int S=1;dist[S]=0;vis[S]=1;//同dij 任选起始点
  for(int i=0;i<n-1;i++){// 将n-1个点做n-1次更新加入集合
    int Min=inf;int ne;// ne 同dij 存最短点
    for(int j=1;j<=n;j++){
      if(!vis[j]){// 未加入集合  **可能与S无边  (与dij不同）
        dist[j]=min(dist[j],G[S][j]);// 松弛  用上一个最近点更新距离
          if(dist[j]<Min){// 更新当前最近的点
              ne=j;Min=dist[j];
          }
      }
    }
    if(Min==inf)return inf;//   不存在
    S=ne;//  赋值给起点
    vis[S]=1;//标记
   res+=Min;
  }
return res;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
memset(G,0x3f,sizeof G);
memset(vis,0,sizeof vis);
for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G[a][b]=G[b][a]=min(G[a][b],c);   //无向图  防重边 自环
}
int ans=prim();
if(ans==inf)puts("impossible");
else cout<<ans<<endl;
    return 0;
}
