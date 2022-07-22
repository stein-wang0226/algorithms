#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e3+5;
int T,n;
int s[N],e[N],w[N],dp[N];
//dp[i]表示前i个时刻的最大收益
// 两种转移  1.第i个时刻不工作 dp[i]=dp[i-1]  2.工作i==ej dp[i]=dp[sj]+w[j]
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
int maxx=0;
for(int i=1;i<=n;i++){
    cin>>s[i]>>e[i]>>w[i];
    maxx=max(maxx,e[i]);
}
dp[0]=0;
for(int i=1;i<=maxx;i++){//时间
dp[i]=dp[i-1];
for(int j=1;j<=n;j++)
if(i==e[j])dp[i]=max(dp[i],dp[s[j]]+w[j]);

}


cout<<dp[maxx]<<endl;



    return 0;
}
