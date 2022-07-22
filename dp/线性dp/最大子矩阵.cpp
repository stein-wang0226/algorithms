#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int inf =0x3f3f3f3f;
const int N = 1e3 + 5;
int T, n,m, a[N];
char Map[N][N];
int num[N][N];
// 最大子矩阵
int sum[N][N];
int dp[N]; //前i列的最大子矩阵
//对于最大连续子序列
//  dp[i]=max(dp[i-1]+a[i],a[i])
//那么拓展到二维  若子矩阵2行 则将相邻两行相加求最大连续子序列即可
// k行同理  那么开一个二维数组 sum[j][k]  表示从i行加到j行的第k列和
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>Map[i][j];
            if(Map[i][j]=='F')num[i][j]=1;
            else num[i][j]=-inf;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){//起始行
        memset(sum,0,sizeof sum);
        for(int j=i;j<=n;j++){//
            for(int k=1;k<=m;k++){
                sum[j][k]=sum[j-1][k]+num[j][k];
            }
            memset(dp,0,sizeof dp);
            for(int t=1;t<=m;t++){ //枚举列
                dp[t]=max(sum[j][t],sum[j][t]+dp[t-1]);
                ans=max(ans,dp[t]);
            }
        }
    }

cout<<ans*3<<endl;
    
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


      solve();
  
  return 0;
}
