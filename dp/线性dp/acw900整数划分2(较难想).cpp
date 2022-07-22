#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e3+5;
//法2  do[i][j]  表示 将i恰分为j个的方法数  
// 考虑小到大的状态转移
// 两种状态  1.分成d 最小值是1   则dp[i][j]->dp[i-1][j-1] 等于少拿一个1的方案数
//          2.   最小值大于1   *** dp[i][j]->dp[i-j][j]  // 等于每个数都减一前的方案数
// 两种情况求和
int T,n; 
int dp[N][N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
dp[0][0]=1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
    }
}
int ans=0;
for(int i=1;i<=n;i++){
    ans+=dp[i];
}
cout<<ans;
    return 0;
}
