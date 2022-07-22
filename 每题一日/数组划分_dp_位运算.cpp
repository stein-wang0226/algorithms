#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//将连续数组划分位k个子数组(连续)，求对每个子数组求和后按位与的最大值
// 首先最高位尽可能是1
//从最高位到低位枚举 先假设该位可以为1
 //结果为x// 再check  x 发现如果区间sum>=x(此处只x为1的位sum都为1)  则 sum&x==x   
//dp[i][k]表示前i个数可以划分位k个满足的子数组
//如果sum(i,j)&x==x  则转移 店dp[i][len]|=dp[j-1][len-1]  
const int N = 2e2 + 5;

int k,T, n, a[N],sum[N];
int dp[N][N];
bool check(int x){
memset(dp,0,sizeof dp);
dp[0][0]=1;
for(int i=1;i<=n;i++){
  for(int j=1;j<=i;j++){//从前往后枚举区间
    int s=sum[i]-sum[j-1];
    if((s&x)==x){
      for(int len=1;len<=k;len++){
        dp[i][len]|=dp[j-1][len-1];   // （i,j）满足则转移 （不同数组数要分开考虑）
      }
    }
  }
}

return dp[n][k];
}




signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }
  int ans=0;
  for(int bit=60;bit>=0;bit--){// 从高位到低位枚举
    ans=ans|((int)1<<bit);//     假设可以先加上
    if(!check(ans))ans=ans^((int)1<<bit);  // 该位不可能为1  减掉
  }
    cout<<ans<<endl;
  return 0;
}
