#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int mod = 998244353;
int T, n, k;
int vis[70];  //标记出现过的位
// x对a[i]满足条件只需 a[i]为1的哪一位x是0即可
// 对a[i]每一个1(cnt个)这些位上有一个0即可(不是11111)(2^cnt-1种)
//  再乘剩下2^(k - cnt) 剩下任意    标记已出现过1的位  之后不用考虑（只能全1）
int a[N];
int cnt[N];      // 每个a[i] 种过的 之前未出现二进制1的个数
int bitpow[70];  //预处理2的幂次
void init() {
  int res = 1;
  for (int i = 0; i <= 65; i++) {
    bitpow[i] = res;
    res = res * 2 % mod;
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  init();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int temp = a[i];
    int bit = 0;
    while (temp) {
      if ((temp & 1 )&& !vis[bit]) cnt[i]++, vis[bit] = 1;
      bit++;
      temp >>= 1;
    }
  }
  int ans = 0;
  int num=k;//未处理过的位置
  for (int i = 1; i <= n; i++) {
    int t = cnt[i];
    num-=t;
    ans += ((bitpow[t] - 1) % mod * (bitpow[num] % mod))*i % mod;
    ans%=mod;
  }
cout<<ans<<endl;

  return 0;
}
