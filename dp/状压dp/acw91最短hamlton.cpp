#include <bits/stdc++.h>
//#define LOCAL
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;
// 最短hamiltin路径
// 状压dp   枚举路径状态  （经过哪些点）
//dp
// 状态转移  ： dp[i][j](i 经过 j和k)=min  0->k (状态i（经过j）) dp[i-(1<<j)][k]+dis[k][j] (k->j)
// 类似 floyed  用k点更新 dp[i][j]
const int N=20;
const int M=1<<N;  // 枚举二进制状态

int T,n,a[N];
int dis[N][N];  //完全图
int dp[M][N];  // 通过M路径 到达点N 的最短路径

signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0); 
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

cin>>n;

for(int i=0;i<n;i++){  // 注意从0开始
  for(int j=0;j<n;j++){
    cin>>dis[i][j];
   
  }
}

memset(dp,0x3f,sizeof dp);dp[1][0]=0;
for(int i=0;i<1<<n;i++){
  for(int j=0;j<n;j++){ // 0~j
    if(i>>j&1) // 经过j
      for(int k=0;k<n;k++ ){
        if(i>>k&1) // 经过k
        // 用k更新
          dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+dis[k][j]);
      }

  }
}

cout<<dp[(1<<n)-1][n-1]<<endl;  // 下标从0  全1（全走过）



    return 0;
}
