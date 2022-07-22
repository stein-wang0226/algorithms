#include <bits/stdc++.h>
#define LOCAL
using namespace std;

double a, b, c, d;
int cnt=0;
double f(double x) { return a * x * x * x + b * x * x + c * x + d; }
bool check(double l, double mid) {
  if (f(l) * f(mid) < 0) return true;  // l~mid有解
  return false;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> a >> b >> c >> d;
  for (int i = -100; i < 100; i++) {  //遍历每个长度为1的区间
    double l = (double)i;
    double r = (double)(i + 1);
    if (f(l) == 0) {
      printf("%.2lf ", l);
      continue;
    }
    if (f(l) * f(r) >= 0) continue;  //等于特判，否则会重复******，只对小于0的情况二分
    while (r - l > 1e-3) {
      double mid = (l + r) / 2;
      if (check(l, mid))
        r = mid;  // l~mid有解则移动右侧
      else
        l = mid;
    }
    printf("%.2lf ", l);cnt++;
    if(cnt==3)return 0;
  }
}