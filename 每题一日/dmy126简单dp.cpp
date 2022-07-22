#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e2+5;
int T,n;
int Map[N][N];
int dp[N][N];
int ok(int i,int j){
    if(i<=n&&i>0&&j<=n&&j>0&&Map[i][j])return 1;
    return 0;
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif


cin>>n;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>Map[i][j];
    }
}
dp[n][n]=1;
for(int i=n;i>0;i--){
    for(int j=n;j>0;j--){
        if(!Map[i][j])continue;
        int xx=i+1;
        int yy=j+1;
        if(ok(xx,j))dp[i][j]+=(dp[xx][j]%mod)%mod;
        if(ok(i,yy))dp[i][j]+=(dp[i][yy]%mod)%mod;
    }
}
cout<<dp[1][1]%mod<<endl;
    return 0;
}
