#include <bits/stdc++.h>
//#define LOCAL
#define int long long
using namespace std;
// acw291  求用1*2的方格填满 m*n 的方案数
//状压dp  1.只需求出横向摆放的所有合法方案数即可(纵向按序填入)
//按列遍历  dp[i][j]  (j<=2^11 二进制表示状态)
//表示第i列，上一列刚放入方格(即覆盖到第i列)(第一块)的状态为j 对应的方案数
//  限制 (设这一列与上一列状态为 j,k)：1.上一列刚放这一列不能再放(不重合)  即
//  i&k=0;    2.一列不能有奇数个0(放下竖条）  j|k  不存在连续奇数个0
//  dp[i][j]+=dp[i-1][k]
// O(4e7)
const int N = 12,M=1<<N;
int T, n, m;
int dp[N][M];
bool st[M];  // 判断该状态是否有连续奇数个0
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  while (cin >> n >> m, n || m) {
    memset(dp, 0, sizeof dp);
    // 预处理st  每种状态是否有里连续奇数个0
    for (int i = 0; i < 1 << n; i++) {  // 遍历状态
      st[i] = 1;
      int cnt = 0;                   // 连续0个数
      for (int j = 0; j < n; j++) {  // n行
        if (i >> j & 1) {            // 第j位是1
          if (cnt & 1) {             // 前面奇数个0
            st[i] = 0;
            break;
          }
          cnt = 0; // 归0
        }
        else cnt++;
      }
        if (cnt & 1) st[i] = 0;  // 最后1格为0
    }

    //状压dp
    dp[0][0] = 1;  // 理解 假设有第0列他只有 0一种状态
    for (int i = 1; i <= m; i++) {          // 遍历列
      for (int j = 0; j < 1 << n; j++) {    // 当前列状态
        for (int k = 0; k < 1 << n; k++) {  // 前一列状态
          if ((j & k) == 0 && st[j | k]) {    // 合法
            dp[i][j] += dp[i - 1][k];
          }
        }
      }
    }

    cout << dp[m][0] << endl;  //  最后一列肯定不能放入
  }
  return 0;
}
