#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e2+5;
const int M=1e2+5;
bool dp[N][M];   // dp[i][j]为i步能否走到j    可滚一维
int vis[M];
int a[N],b[N];
int T,n,m;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
}

memset(vis,0,sizeof vis);
dp[0][0]=1;
for(int i=1;i<=n;i++){// 步数
    for(int j=1;j<=m;j++){  // 位置
            if(j>=a[i])dp[i][j]|=dp[i-1][j-a[i]];
            if(j>=b[i])dp[i][j]|=dp[i-1][j-b[i]];
    }
}

for(int i=0;i<=m;i++){
    if(dp[n][i])cout<<"1";
    else cout<<"0";
}
cout<<endl;
    return 0;
}
