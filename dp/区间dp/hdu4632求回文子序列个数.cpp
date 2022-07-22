#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 求回文序列数  dp[i][j]  表示区间 [i,j]的回文序列数 (容斥)
// =不包含j的所有回文序列+不包含i的所有回文序列-既不包含头也不包含尾
// +既包含头也包含尾的
// dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1].也就是左右两个比他小1的区间之和再减去重复的部分。
//特殊情况：当左右端点相等时，左右端点加上中间任意一个回文子序列都可以构成一个新的回文序列，而且左右端点还可以自己构成一个回文序列，所以当端点相等时还要加上dp[i+1][j-1]+1.

using namespace std;
const int N = 1e3+ 7;
const int mod=10007;
int T, n;
int dp[N][N];
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> T;
  string s;
  int Case=0;
  while (T--) {
    cin >> s;
    printf("Case %d: ",++Case);
    int n = s.size();
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) {
      dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]+mod)%mod;
        if (s[i] == s[j]) dp[i][j] += dp[i + 1][j - 1] + 1,dp[i][j]%=mod;
      }
    }


      int ans = dp[0][n - 1]%mod;
  cout<<ans<<endl;
  }


  return 0;
}
