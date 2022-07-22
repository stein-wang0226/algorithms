#include <bits/stdc++.h>
#define LOCAL
#define int long long
// 区间dp  dp[i][j]表示 i,j区间首伤害最小值
//  枚举[i,j]中 k代表最后杀哪头,(最后不会受到区间内元素)
// 将k左右两个区间看作两个单位  则dp[i][j]=min(dp[i][k-1]+dp[i][k+1]+a[k]+b[i-1]+b[j+1])   
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e3+5;
int T,n;
int a[N],b[N];
int dp[N][N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
int Case =0;
while(T--){
printf("Case #%d: ",++Case);
cin>>n;
memset(dp,0,sizeof dp);  // 非法区间为0
for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        dp[i][j]=inf;   // 最小值  合法区间初始化inf
    }
}
memset(a,0,sizeof a);
memset(b,0,sizeof b);
for(int i=1;i<=n;i++)cin>>a[i];// 长度为1的区间
for(int i=1;i<=n;i++)cin>>b[i];
for(int i=1;i<=n;i++)dp[i][i]=a[i]+b[i-1]+b[i+1];// 长度为1的区间

for(int len=2;len<=n;len++){
    for(int i=1;i<=n-1;i++){
        int j=i+len-1;
        for(int k=i;k<=j;k++){
            dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
        }
    }
}


cout<<dp[1][n]<<endl;
}
    return 0;
}
