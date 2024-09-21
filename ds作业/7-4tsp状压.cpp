#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 17 ;
int T, n,m, a[N];
int dis[N][N],dp[1<<N][N];
void solve(){
  memset(dp,0x3f,sizeof dp);
  memset(dis,0x3f,sizeof dis);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>dis[i][j];
    }
  }

//    for(int k=1;k<=n;k++)
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    dp[1][1]=0; //从1出发

    for(int i=0;i<(1<<n);i++){
      for(int j=1;j<=n;j++){
        if(i&(1<<(j-1)))
          for(int k=1;k<=n;k++){
            if(i&(1<<(k-1)))
              dp[i][j]=min(dp[i][j],dp[i^(1<<(j-1))][k]+dis[k][j]);
                    //  if(i&(1<<k-1))continue;
                    //  dp[i|(1<<(k-1))][k]=min(dp[i|(1<<k-1)][k],dp[i][j]+dis[j][k]);
          }
        }
      }
    //这里要求回到1 所以对每个终点+ dis[i][1]取max
      cout<<dp[(1<<n)-1][n]<<endl;

//若求最小哈密尔顿  则  ans= d[1<<n-1][n]

    }
    signed main() {
      std::ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);


      while (cin>>n) {
        solve();
      }
      return 0;
    }
