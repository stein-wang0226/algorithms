#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//题意：有d1 .d2. ...dn  ;t1 t2....tn  每次可使d[i]=d[i]+d[i+1],ti=ti+ti+1,同消除i+1在k次操作内
//dp   dp[i][j]代表前i个元素经j次操作的最小值   转移方程（移除i+1~pos-1）：dp pos,j+pos−i−1=min(dp pos,j+pos−i−1,dpi,j+bi∗(apos−ai)).//区间dp
//pos>i  因为移除区间的t都为前面的t[i]
int n,l,k;
long long d[505],t[505],a[505];
int dp[505][505];
int min(long long a,long long b){
    return a<b?a:b;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>l>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
a[n+1]=l;
for(int i=1;i<=n;i++){
    cin>>t[i];
}
memset(dp,0x3f,sizeof dp);
dp[1][0]=0;
for(int i=2;i<=n+1;i++){
    dp[i][0]=dp[i-1][0]+t[i-1]*(a[i]-a[i-1]);
}
for(int i=1;i<=n;i++){
    for(int j=0;j<=k&&j<i;j++){
       for(int m=i+1;m<=n+1;m++){//区间操作  移除i+1~m-1
            dp[m][j+m-i-1]=min(dp[m][j+m-i-1],dp[i][j]+t[i]*(a[m]-a[i]));//****
//Why such formula? After removing all the signs between [i+1,pos−1] we will stay on
// the sign pos, remove pos−i−1 signs, and the time to go from i to pos will depend on the sign i and the distance between i and pos.
       }
    }
}
int ans=0x3f3f3f3f;
for(int i = 0; i <= k; i++) ans = min(ans, dp[n + 1][i]);//取最小
	cout << ans << endl;
    return 0;
}
