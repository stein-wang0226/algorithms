#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e3+5;
int T,n;
int dp[N],a[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){
  cin>>a[i];
  dp[i]=1;
}
int  ans=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++){//找之前小的
      if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
    }
    ans=max(ans,dp[i]);
}
cout<<ans<<endl;
    return 0;
}
