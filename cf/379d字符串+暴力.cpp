#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N = 1e18 + 5;
int T, n;
int bitpow[100], tot;
void init() {
  int res = 1;
  for (int i = 0; res < N; i++) {
    bitpow[i] = res;
    res <<= 1;
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
  init();  //预处理二的幂次
  cin >> T;
  while (T--) {
    cin >> n;
    string s = to_string(n);
    int len2 = s.size();
    int ans = 100;
    for (int i = 0; i <= 58; i++) {
      string s1 = to_string(bitpow[i]);
      int len = s1.size();
      int pos = 0;
      int cnt = 0;  // 匹配的的序列长度
      for (int j = 0; j < len2 && pos < len; j++) {
        if (s[j] == s1[pos]) {
          cnt++;
          pos++;
        }
      }
      ans = min(ans, len2 - cnt + len - cnt);
      // cout<<ans<<endl;
    }


    cout << ans << endl;
  }
  return 0;
}
