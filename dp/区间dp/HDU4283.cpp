#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 怒气值= 等待时间*a[i]
// 小黑屋 （栈）  从前往后安排入栈
//不难想到区间DP：dp[i, j]。 区间[i,j]的不满 值
//若第i个人是第1个上台（i~j中），那么dp[i, j]转移至dp[i + 1, j]+sum[i+1,j ]*1  //
//否则，不妨令此人是第k个人上台。那么不难发现，在这样的一种排序方式中，前k - 1上台的人一定是i之后连续k - 1个人顺序有所调整。(栈的性质)
//则必有：dp[i, j] = max{dp[i , j], dp[i + 1, i + k - 1] + dp[i + k][j] + (k - 1) * D[i] + (sum[j] - sum[i + k - 1]) * k}； 
using namespace std;
const int N=1e5+5;
int T,n;
int dp[105][105];
int sum[105],a[105];

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
memset(sum,0,sizeof sum);
for(int i=1;i<=n;i++){
  cin>>a[i];
  sum[i]=sum[i-1]+a[i];//区间和
}
for(int i=1;i<=n;i++){
  for(int j=i+1;j<=n;j++)dp[i][j]=0x3f3f3f3f;
  dp[i][i]=0;
}
for(int len=2;len<=n;len++){//长度从2开始
  for(int i=1;i<=n;i++){
    int j=i+len-1;
    dp[i][j]=dp[i+1][j]+sum[j]-sum[i]; // i 为[i,j]中第一个上  

    for(int k=2;k<=len;k++){//  i 为[i,j]中第k个上   
      dp[i][j]=min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+(k-1)*a[i]+(sum[j]-sum[i+k-1])*k);// i 的怒气增加  后半段的等待要加上
    }
  }
}
cout<<dp[1][n]<<endl;

}
    return 0;
}
