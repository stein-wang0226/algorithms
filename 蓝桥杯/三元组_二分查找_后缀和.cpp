#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//
const int N = 2e5 + 5;
int T, n, a[N],b[N],c[N];
int cnt1[N],sum[N],cnt2[N];//对b中每个数 在c中大于它的个数   a 在bc中大于的总数
//sum:求后缀和
void solve(){
  std::cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
      for(int i=1;i<=n;i++)cin>>c[i];
        sort(a+1,a+1+n);
      sort(b+1,b+1+n);
      sort(c+1,c+1+n);

      for(int i=1;i<=n;i++){
        auto pos = upper_bound(c+1,c+1+n,b[i]);
        cnt1[i]= c+1+n-pos;
      }
for(int i=n;i>=0;i--){//后缀和
  sum[i]=sum[i+1]+cnt1[i];
}
int ans=0;
for(int i=1;i<=n;i++){
  auto pos = upper_bound(b+1,b+1+n,a[i])-(b);
  ans+=(sum[pos]);
}
cout<<ans<<endl;






}
signed main() {

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  T=1;
  while (T--) {
    solve();
  }
  return 0;
}
