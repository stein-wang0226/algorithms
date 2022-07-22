#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
// 倒着遍历画家防止覆盖
int T, n, m, a[N], b[N], c[N];
vector<int> g[N];  //  每种需要被染成的颜色 对应的木板编号
//先贪心考虑颜色一致不需要被染
//再倒着操作  首先最后一个画家不需要染  后面能染则染
//不能则让其被最后一个画家木板覆盖 用vector 模拟栈实现储存画板编号
int ans[N];  // 答案
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear(), cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) g[b[i]].push_back(i);  // 记录需要染的部分
    }
    memset(ans, -1, sizeof ans);
    int last = -1;
    if (g[c[m]].size()) {     //最后一个画家的颜色有需要
      last = g[c[m]].back();  //
      g[c[m]].pop_back();
    } else {
      for (int i = 1; i <= n; i++)  //或者最后一个画家的颜色对应正确 （重复）
        if (b[i] == c[m]) last = i;
    }
    if (last == -1) {
      cout << "NO" << endl;
      continue;
    }
    ans[m] = last;                     //最后画家答案
    for (int i = m - 1; i > 0; i--) {  //倒序遍历
      if (g[c[i]].size()) {
        ans[i] = g[c[i]].back();
        g[c[i]].pop_back();
      } else {
        ans[i] = last;  //让他被最后一个画家覆盖
      }
    }
//判断
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      if (g[i].size()) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
      for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
    else
      cout << "NO" << endl;
  }
  return 0;
}
