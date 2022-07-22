#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int T, n, a[100005];
//给定 a[]  求 (i,j)  对数 使得 ai&aj>=ai^aj
//只需判断第一位
// ：1 1  >  1 0/0 1  <
//按位数排序 位数不同即10  <   位数相同>
//求每位 位数相同的个数 取组合数
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> T;
  while (T--) {
    cin >> n;
    int b[50];  //桶
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      int cnt = 0;
      while (a[i]) {
        a[i] >>= 1;
        cnt++;
      }
      b[cnt]++;  //
    }
    int ans = 0;
    for (int i = 0; i < 50; i++) {
      int k = b[i];
      if (k) ans += k * (k - 1) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
