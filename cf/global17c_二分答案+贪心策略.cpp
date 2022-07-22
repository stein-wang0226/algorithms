#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int N = 2e5 + 5;
int T, n, m, a[N], b [N];
//二分答案求最大值--能邀请max个则肯定能邀请小于max个，不能大于max个；

int check(int x) {  //贪心策略 从小选
  int c = 0;        //已邀请数
  for (int i = 1; i <= n; i++) {
    if (x - 1 - a[i] <= c && c <= b[i]) c++;  //
  }
  return x <= c;
}
//设答案为x,先找一个i满足ai-(x-1)>=0 比他富得不超过ai个   做第一个最穷的//
//之后x-1个满足序号递增 且 x−1−av≤i−1≤bv    i为邀请后序号
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
    }
    int l=0;int r=N;
    while(l<r){
      int mid=(l+r+1)>>1;//偏右
      if(check(mid))l=mid;
      else r=mid-1;
    }

    cout<<l<<endl;
  }
  return 0;
}
