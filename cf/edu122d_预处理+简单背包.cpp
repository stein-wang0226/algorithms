#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//
const int N = 1005;
int T,k, n, c[N], b[N], w[N],v[N],dp[1000005];

void init() {
  memset(w, 0x3f, sizeof w);
  w[1] = 0;  //
  for (int i = 1; i <= 1000; i++) {//从小到大枚举即可
    for (int j = 1; j <= i; j++) {
      int t = i / j;
      if (i + t <= 1000) w[i + t] = min(w[i + t], w[i] + 1);
    }
  }
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  // 01背包
  init();
  cin >> T;
  while (T--) {
    cin >> n>>k;
    memset(v,0,sizeof v);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      v[i]=w[b[i]];
    }

    for (int i = 1; i <= n; i++) {
      cin >> c[i];  // value
    }
  memset(dp,0,sizeof dp);
dp[0]=0;
for(int i=1;i<=n;i++){
  for(int j=k;j>=v[i];j--){
    dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
  }
}
int ans=0;
for(int i=0;i<=k;i++){
  ans=max(ans,dp[i]);//注意这步
}
cout<<ans<<endl;
  }
  return 0;
}
