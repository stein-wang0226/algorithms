#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
//期望dp入门 投色子
//从后往前
// dp[] 表示还需要扔的期望次数
// 初始化dp[n]=dp[n+1]=...dp[n+5]=0;  //末状态
//  跳跃  dp[x]=dp[y]   // x->y 倒推
//  否则 dp[i]=1/6(dp[i+1]+...dp[i+6])+1    +1指最后扔了一次

#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

int T, n, m, a[N];
int nex[N];  //跳跃
int x[N], y[N];
double dp[N];
signed main() {
  while (cin >> n >> m,m+n) {
      memset(dp,0,sizeof dp);
      memset(nex,-1,sizeof nex);
      for (int i = 1; i <= m; i++) {
      cin >> x[i] >> y[i];
      nex[x[i]] = y[i];
    }
    for (int i = n-1; i>= 0; i--) {  //倒推
      if (nex[i] == -1) {          //不跳
            dp[i]=1.0/6*(dp[i+1]+dp[i+2]+dp[i+3]+dp[i+4]+dp[i+5]+dp[i+6])+1.0;
      }
      else dp[i]=dp[nex[i]];
    }
    printf("%.4lf\n",dp[0]);
  }
  return 0;
}
