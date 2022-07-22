#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
using namespace std;
const int N=2e2+10;
int V,n;
int v[N],s[N],w[N];
int dp[N][N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>V;
for(int i=1;i<=n;i++)
{
    cin>>v[i]>>w[i]>>s[i];
}

for(int i=1;i<=n;i++){
    for(int j=0;j<=V;j++){
        for(int k=0;k<=s[i]&&k*v[i]<=j;k++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]*k]+w[i]*k);
        }
    }
}
cout<<dp[n][V];


    return 0;
}
