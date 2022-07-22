#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//每次合并相邻两堆
using namespace std;
const int N=1e3+5;
int T,n,a[N],sum[N],dp[N][N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sum[1]=a[1];
for(int i=2;i<=n;i++){//前缀和求区间和 （i,j）区间  这堆石子的数量
    sum[i]=sum[i-1]+a[i];
}
memset(dp,0,sizeof dp);//  dp[i][i]  长度为1区间默认0  （）不用花费
//  区间dp  dp[i][j]  表示(i,j)区间 最小值 枚举k  dp[i][j]=min( dp[i][k], (dp[k+1][j])  +w)//长度较短的区间已生成过
for(int len=2;len<=n;len++){//长度》=2
    for(int i=1;i+len-1<=n;i++){//枚举左端点
        int j=i+len-1;      //  右端点
        dp[i][j]=0x3f3f3f3f;
        for(int k=i;k<j;k++){// 枚举分界点k
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
        }
        
    }
}
cout<<dp[1][n]<<endl;


    return 0;
}
