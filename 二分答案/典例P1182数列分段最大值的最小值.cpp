#include <cstdio>
#include <iostream>
#define LOCAL  //数列分段->典例 使最大值最小,求该最小值 模板2
using namespace std;
const int Manx = 1e5 + 5;
int n, m;
long long a[Manx], Sum = 0;
int check(long long mid) {  //检查mid是否能为分为m段的最大值(或更大*)（**mid是否够大）（仍位于合法区间）
  long long sum = 0, cnt =1;
            //保证分为m段时每段小于mid
              //->先保证每段小于mid，求得段数（尽量少）cnt<=m,则保证m段时必小于
  for (int i = 1; i <= n; i++) {
    if (sum + a[i] <= mid) {
      sum += a[i];  //不会超过mid(max)则继续加
    } else {
      if (a[i] <= mid) {
        sum = a[i];  //加a[i]会超过,则清零从a[i]开始加
        cnt++;
      } else
        return 0;  //
    }
  }
  if (cnt <= m)
    return 1;  //****若cnt段每段都小于mid，那么m段一定小于，则mid大于此最小情况的最大值
    return 0;  //***需要分为大于m段，说明若分为m段时最大值必大于mid    mid太小
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    Sum += a[i];
  }
  long long l = 1, r = Sum;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {  //仍位于合法区间，继续向左寻找边界
      r = mid;         // r始终在合法区间
    } else
      l = mid + 1;
  }
  cout << r;

  return 0;
}
