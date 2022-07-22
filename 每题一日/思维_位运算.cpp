#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N];
int m,d;
//对相同位数的数最多只能选一个
//递增  考虑最高位即可
//eg ：  d=5   [1] [10 ,11 ]  [100,101,110]     =(1+1)*(1+2)*(1+3)-1  减去全不选
// 
int res=0,ans=1;

void solve() {
    cin >> d >> m;
    int res = 0;
    int ans = 1;
    for (int i = 0; i <= 32; i++) {
        int pw = 1ll << (i);
        res += pw;
        if (res < d) {
            ans *= (pw + 1);
            ans %= m;
        }
        else if (res == d) {
            ans *= (pw + 1);
            ans %= m;
            break;
        }
        else {
            res-= 1ll << ((i ));
            int t = d - res;
            ans *= (t + 1);
            ans %= m;
            break;
        }
    }
    cout << (ans - 1 + m) % m << endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
