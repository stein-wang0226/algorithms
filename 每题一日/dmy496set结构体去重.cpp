#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n;
// 对dy/dx 相同的使用同一种魔法 令gcd=gcd(abs(dx),abs(dy)) 则取a=dx/gcd ,b=dy/gcd  最优
// （尽量取最小）
//分别算出没对 a,b  去重计数  
int x[N], y[N];
struct Node {
  int a, b;
  bool operator<(const Node& m) const {  //一定要const
    if(a==m.a)return b<m.b;   // 注意偏序  不然无法去重
    return a < m.a;
  }
} p[N];
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
    cin >> x[i] >> y[i];
  }
  set<Node> st;  //需要重载<
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(i==j)continue;
      int dx = (x[i] - x[j]);
      int dy = (y[i] - y[j]);
      if (dx == 0 || dy == 0) {
        st.insert({dx, dy});
      } else {
        int gcd = __gcd(abs(dx), abs(dy));
        int a = dx / gcd;
        int b = dy / gcd;
        st.insert({a, b});
      }
    }
  }
  int ans = st.size();
  cout << ans  << endl;
  return 0;
}
