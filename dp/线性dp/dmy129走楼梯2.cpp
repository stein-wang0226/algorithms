#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N=1e5+5;
int T,n;
int dp[55][4];//第二维存是第几个2阶
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
dp[0][0]=1;
dp[1][0]=1,dp[2][0]=1;dp[2][1]=1;

for(int i=3;i<=n;i++){
    dp[i][0]=(dp[i-1][0]+dp[i-1 ][1]+dp[i-1][2]);
    dp[i][1]=dp[i-2][0];
    dp[i][2]=dp[i-2][1];
}

int ans=dp[n][0]+dp[n][1]+dp[n][2];
cout<<ans<<endl;
    return 0;
}
