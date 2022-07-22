#include <bits/stdc++.h>
#define LOCAL
// 
#define int long long
//两组数和尽量接近即可
//dp[i][j] （1，0）  表示a前i个数的和为j
// 公式(见题解)(n−2)⋅∑ni=1(a2i+b2i)+(∑ni=1ai)^2+(∑ni=1bi)^2
const int inf =0x7fffffff;
const int N=1e5+5;
int a[105],b[105],dp[105][N];
using namespace std;
int T,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
  cin>>n;
  int sum=0;
for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
for(int i=1;i<=n;i++)cin>>b[i],sum+=b[i];

memset(dp,0,sizeof dp);
dp[0][0]=1;//
for(int i=1;i<=n;i++){//01背包
    for(int j=0;j<=sum;j++){//这里不能滚动  有两次赋值会相互影响  背包体积不能
      if(j>=a[i]&&dp[i-1][j-a[i]])dp[i][j]=1;//  可变为 j
      if(j>=b[i]&&dp[i-1][j-b[i]])dp[i][j]=1;//  同理
    }
}

int ans=inf;
for(int i=0;i<=sum;i++){
  if(dp[n][i])ans=min(ans,i*i+(sum-i)*(sum-i));//其实肯定在  sum/2附近
}


for(int i=1;i<=n;i++)ans+=(n-2)*(a[i]*a[i]+b[i]*b[i]);
cout<<ans<<endl;
}
    return 0;
}
