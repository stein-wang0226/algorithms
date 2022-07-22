#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;
//合唱队形  先dp正向最大上升子序列 ，再dp反向   将两这相加取最大值
int n, a[105], dp1[105], dp2[105];
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dp1[1] = 1;
  for (int i = 1; i <= n; i++) {
    dp1[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + 1);  //找到最长的那位接上
    }
  }
for (int i = n; i >= 1; i--) {//倒序
    dp2[i] = 1;
    for (int j = n; j >i; --j) {
      if (a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + 1);  //找到最长的那位接上
    }
  }
int MAX=0;
for(int i=1;i<=n;i++){
	MAX=max(MAX,dp1[i]+dp2[i]);
}
MAX--;
cout<<n-MAX;
  return 0;
}
