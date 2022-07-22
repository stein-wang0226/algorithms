#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
#define int long long
using namespace std;
//题意  给定n个键值对pair  每次选相邻两个pair 如果first
//b不互质就将他们都删掉，并获得second之和的分数之和 区间dp dp[i][i]为区间 [i,j]
//的最大值 状态转移：  (遍历k)dp[i][j]=dp[i][k]+dp[k+1][j] 特别的
//当中间都被删完：即** （dp[i+1][j-1]==sum(i+1,j-1)) 此时如果互质
//：dp[i][j]=dp[i+1][j-1]+b[i]+a[j]
// 细节处理
const int N = 2e3 + 5;

int T, n, a[N], b[N], sum[N];
int dp[N][N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      sum[i] = sum[i - 1] + b[i];
    }
  
  memset(dp,0,sizeof dp);
  for(int len=2;len<=n;len++){
    for(int i=1;i+len-1<=n;i++){
      int j=i+len-1;
      
      for(int k=i;k<j;k++){
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);  //
      }
      
      if(sum[j-1]-sum[i]==dp[i+1][j-1]){ // 特殊
          if(__gcd(a[i],a[j])>1)// 互质
              dp[i][j]=max(dp[i][j],dp[i+1][j-1]+b[i]+b[j]);
      }
    }
  }
  
  cout<<dp[1][n]<<endl;
  }
  return 0;
}
