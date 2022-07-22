#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
// 一个环。
// 两个兔子单方向的跳（可以多格），但是自己的方向上不能超过以前的节点。并且要求每次所在节点的权值相同。要求最多可以跳多少轮。
// 思路：
// 本质就是最长回文子序列。只要两个兔子在回文子序列的对应节点上，就可以跳完整条链。
// 定义dp[i][j]为i到j的最长回文子序列。
//答案为max{dp[1][i] + dp[i + 1][j]}。
//将环的链视为长度为两倍的链的子链
//求最长回文子序列
// dp[i][j]为  i到j最长回文序列
//考虑到可以从同一石子开始跳  所以1. 不同石子起跳dp[i][i+n-1]2.同一石子起跳
// dp[i][i+n-2]+1 (挖掉起跳点)

const int N = 2e3 + 5;

int T, n, a[2 * N];
int dp[N][N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n, n) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[i][i] = dp[i + n][i + n] = 1;
      a[n + i] = a[i];  // 加长一倍
    }

    //区间dp
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len - 1 <= 2 * n; i++) {
        int j = i + len - 1;
        if (a[i] != a[j])
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  // ** 转移
        else
          dp[i][j] = dp[i + 1][j - 1] + 2;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[i][i + n - 1]);
      ans = max(ans, dp[i][i + n - 2] + 1);  // 同一个石子起跳
    }
    cout << ans << endl;
  }
  return 0;
}
