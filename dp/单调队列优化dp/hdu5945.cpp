#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//题意:给你三个数x，k，t 有两种操作 1.X=X−i(0<=i<=t) .2. if k|X,X=X/k . 问最少经过多少步使得x->1
// dp[i]=min(dp[i],dp[i/k]+1)  dp[i]=min(dp[i],dp[j]+1)(i-t<=j<i)
// 对第二个单调队列优化  递增
const int N = 2e6 + 5;
int T, n, a[N];
int q[N];
int x,t,k;
int dp[N];//dp[i]  i到达1的最小次数
void solve(){
    cin>>x>>k>>t;
    int head=0,tail=0;
    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    for(int i=1;i<=x;i++){
        if(head<=tail&&i-t>q[head])head++;
        //dp
        dp[i]=min(dp[i],dp[q[head]]+1);//
        if(i%k==0)dp[i]=min(dp[i],dp[i/k]+1);
        while(head<=tail&&dp[q[tail]]>=dp[i])tail--;
        q[++tail]=i;
    }
cout<<dp[x]<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
