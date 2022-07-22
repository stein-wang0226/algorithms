#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//每次合并相邻两堆
//最长公共子序列   (max可重复性)
//**dp[i][j] 表示a的前i个元素和b的前j个元素的公共最长子序列
// 若 a[i]!=b[j]  dp[i][j]=max(dp[i-1)[j],dp[i][j-1])  (包含了dp[i-1)[j-1]
// a[i]==b[j]   dp[i][j]=(dp[i-1][j-1]+1)
using namespace std;
const int N=1e3+5;
int m,n,dp[N][N];
char a[N],b[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
cin>>a + 1>>b+1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
    }
}    
    cout<<dp[n][m]<<endl;


    return 0;
}
