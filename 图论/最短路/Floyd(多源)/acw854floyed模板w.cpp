#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
using namespace std;
//floyed 求多源最短路
// 原理  用每个点 松弛每条边
const int N=205;
const int inf=0x3f3f3f3f;
int n,m,K;
int dis[N][N];
void init(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)dis[i][j]=0;
      else dis[i][j]=inf;
    }
  }
}
signed main(){
cin>>n>>m>>K;//m条边 k个询问
init();
for(int i=1;i<=m;i++){
  int u,v,w;
  cin>>u>>v>>w;
  dis[u][v]=min(dis[u][v],w);//   u==v 的特殊情况
}
//floyed
for(int k=1;k<=n;k++){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  }
}

//
for(int i=1;i<=K;i++){
  int a,b;
  cin>>a>>b;
 if(dis[a][b]>inf/2) puts("impossible");// inf/2  ---负环
  else cout<<dis[a][b]<<endl;
}
    return 0;
}
