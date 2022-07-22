#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
#define int long long
using namespace std;

const int N = 2e5 + 5;
//设两个属性a,b
//反向做  即求 三个数既有a相同又有b相同
//因为a,b 不能同时相同所以只能是 x,y a相同  y,z b相同...
//所以遍历元素 y  即可
int T, n, a[N];
struct Node {
  int a, b;
} p[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> T;
  while (T--) {
    cin >> n;
    map<int, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
      cin>>p[i].a >> p[i].b;
      mp1[p[i].a]++;
      mp2[p[i].b]++;
    }
int sum=0;
    for(int i=1;i<=n;i++){
        int aa=p[i].a;
        int bb=p[i].b;
        sum+=(mp1[aa]-1)*(mp2[bb]-1);
    }
int ans=n*(n-1)*(n-2)/6;
ans-=sum;
cout<<ans<<endl;

  }
  return 0;
}
