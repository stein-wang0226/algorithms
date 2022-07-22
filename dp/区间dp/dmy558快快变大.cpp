#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
#define int long long
//就是合并石子变式  --三维  存两个答案
//区间dp
using namespace std;

const int N = 300 + 5;
const int mod = 1000003;
int T, n, a[N];
int dp[N][N][2];  // ij0 存合并的值  ij1 存最大分数
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i][1] = 0;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i][0] = a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = len + i - 1;
      for (int k = i; k < j; k++) {
        int temp= dp[i][k][1] + dp[k + 1][j][1] +
                              (dp[i][k][0] - dp[k + 1][j][0]) *
                                  (dp[i][k][0] - dp[k + 1][j][0]);
        if (dp[i][j][1] < temp) {
          dp[i][j][1] = temp;
          dp[i][j][0] = (dp[i][k][0] * dp[k + 1][j][0]) % mod;       // 当区间更新后其储存的答案才改变  （否则该值不会被用到）
        }  
      }
    }
  }

  cout << dp[1][n][1] << endl;

  return 0;
}
