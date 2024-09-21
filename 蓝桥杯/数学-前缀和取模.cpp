#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
// k倍区间  n,k 1e5   暴力前缀和 O(n^2)
// 方法 前缀和取模** 记录每个模值出现次数cnt[m]** (两位置模相同则为k被区间)  sigmaC(cnt[m],2) +cmt[0]     O(n+k)
int n,k;
int a[N];
int sum[N];//前缀和取模
int cnt[N]; // sum模值出现次数
set<int>nums; // 存出现过的模值


void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i],sum[i]=(sum[i-1]+a[i])%k,cnt[sum[i]]++,nums.insert(sum[i]);
    int ans=cnt[0];
  for(auto i:nums){
    ans+=cnt[i]*(cnt[i]-1)/2;
  }
  cout<<ans<<endl;

}
signed main() {

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
