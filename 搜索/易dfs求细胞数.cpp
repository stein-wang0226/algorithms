#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
//dfs
int m,n;
int  map[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y){
    map[x][y]=0;//访问过或非法越界都变0
  for(int i=0;i<4;++i){
    if (map[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i]);
  }
}
int main()
{
// std::ios::sync_with_stdio(false);
// cin.tie(0); 
// cout.tie(0);

 //   clock_t c1 = clock();
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
  cin>>n>>m;
  memset(map,0,sizeof map);
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      scanf("%1d",&map[i][j]);//只读一个
    }
  }
  int ans=0;
 for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      if(map[i][j]){
        dfs(i,j);
      ans++;
      }
    }
  }
cout<<ans;

    return 0;
}
