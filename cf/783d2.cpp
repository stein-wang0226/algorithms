#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
// 考虑如果两个数减去多次k后可相等   则a mod k=b mod k;
// 所以只要遍历k的取值   看看是否又一半的a 余数相等即可
// k 取遍两两差值的gcd/因子即可
const int N = 2e3 + 5;

int T, n, a[N];
int check(int k){//check k是否能让超过一般余数相同
  map<int,int>mp;
  for(int i=1;i<=n;i++)mp[(a[i]%k+k)%k]++; // 余数
  for(auto i:mp)if(i.second>=n/2)return 1;
  return 0;
}


signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> T;
  while (T--) {
    cin >> n;
    map<int,int>mp;
    for (int i = 1; i <= n; i++) cin >> a[i],mp[a[i]]++;
    int flag=1;
    for(auto i:mp){if(i.second>=n/2){flag=0;break;}}// 超过一半相同
    if(!flag){cout<< -1<<endl;continue;}
    //枚举差值因子
    sort(a+1,a+1+n);
    int ans=1;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        int d=a[j]-a[i];
        for(int k=1;k<=d/k;k++){
          if(d%k==0){   ///枚举因子
            if(check(k))ans=max(ans,k);
            if(check(d/k))ans=max(ans,d/k);
          }
        }
      }
    }
  cout<<ans<<endl;


  }
  return 0;
}
