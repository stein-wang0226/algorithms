#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
using namespace std;

const int N = 2e3 + 5;

//思路  首先答案是每段的gcd 所以是sum(a[i])的因子
// 枚举因子x  如果环上有cnt模x值相同,则有cnt段和为****（前缀和+取模）判断区间和
// 那么肯定有k段区间和都为x倍数即可满足  用cnt 更新maxx[cnt]
int T, n, a[N], Sum, ans[N];
int sum[N];  // 前缀和
void cal(int x) {
  map<int, int> mp;  // 记录和为x倍数最大段数
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    mp[sum[i] % x]++;
    cnt = max(cnt, mp[sum[i] % x]);  //记录最大段数
  }
  ans[cnt] = max(ans[cnt], x); //取最大
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(sum,0,sizeof sum);
  memset(ans,0,sizeof ans);
  for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
  Sum = sum[n];
  for (int i = 1; i<= Sum/i; i++) {
    if (Sum % i == 0) {  //因子、
      cal(i);
      cal(Sum / i);
    }
  }
  for (int i = n; i > 0; i--)
    ans[i] = max(ans[i], ans[i + 1]);  // 保证递减（后面答案也肯定可满足前面）
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;

  return 0;
}
