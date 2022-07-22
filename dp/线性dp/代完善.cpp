
// //1,二维dp
// #include <iostream>
// #include <cstdio>
// #include <ctime>
// #include<cstring>
// #define LOCAL
// using namespace std;
// //dp[i][j]  第i件物品之前还有j个物品的情况的耐久度最大值
// // dp[i][j] = max(dp[i-1][k]+a[j]*k)(j-s<=k<=j<=w)//滚掉一维
// long long n,w,s,a[5005],dp[5005][5005];
// long long max(long long a,long long b){
//   return a>b?a:b;
// }
// int main()
// {

// #ifdef LOCAL
//     freopen("data.in","r",stdin);
//     freopen("data.out","w",stdout);
// #endif
// cin>>n>>w>>s;
// for(int i=1;i<=n;++i){
//   cin>>a[i];
// }
// memset(dp,-0x3f3f3f3f,sizeof dp);//***存在负数负无穷
// dp[0][0]=0;
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=w&&j<=i;j++){
//         for(int k=j-1;k<=j+s-1&&k<=w;k++){//拿之前的个数
//           dp[i][j]=max(dp[i-1][k]+a[i]*j,dp[i][j]);
//         }
//     }
// }
// long long ans=-1e18; 
// for(int i=1;i<=w;i++){
//   ans=max(dp[n][i],ans);
// }
// cout<<ans;
  
//     return 0;
// }

//滚动一维

#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
//dp[i][j]  第i件物品之前还有j个物品的情况的耐久度最大值
// dp[i][j] = max(dp[i-1][k]+a[j]*k)//滚掉一维
long long n,w,s,a[5005],dp[2][5005];
long long max(long long a,long long b){
  return a>b?a:b;
}
int main()
{
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>w>>s;
for(int i=1;i<=n;++i){
  cin>>a[i];
}
memset(dp,-1e15,sizeof dp);//***存在负数负无穷
dp[0][0]=0;
int now=1;//
for(int i=1;i<=n;i++){
  for(int m=0;m<=w;m++)dp[now][m]=-1e15;//**滚动的需要每次清零
    for(int j=1;j<=w&&j<=i;j++){
        for(int k=j-1;k<=j+s-1&&k<=w;k++){//拿之前的个数
          dp[now][j]=max(dp[now^1][k]+a[i]*j,dp[now][j]);
        }
    }
    now^=1;
}
long long ans=-1e17; 
for(int i=1;i<=w;i++){
  ans=max(dp[n&1][i],ans);
}
cout<<ans;
  
    return 0;
}

