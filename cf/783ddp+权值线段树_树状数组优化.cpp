#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 5e5 + 5;
//dp[i]  表示前i个中value和的最大值
// 转移   [j+1,i]若区间和>0 则 dp[i]=max(dp[i],dp[j]+(i-j))//  更新
// 这样 O(n^2)
const int inf=1e18;
int T, n, a[N];
int dp[N];
int s[N]; //离散化后pre
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      cin>>n;
    memset(pre,0,sizeof pre);
   // O(n^2)暴力做法
   vector<int>s(n);
    for(int i=1;i<=n;i++)cin>>a[i],s[i-1]=s[i-2]+a[i];
    // for(int i=1;i<=n;i++){
    //     dp[i]=-inf;
    //     for(int j=0;j<i;j++){//从零开始
    //         if(pre[i]-pre[j]>0)dp[i]=max(dp[i],dp[j]+(i-j));
    //         else if(pre[i]==pre[j])dp[i]=max(dp[i],dp[j]);
    //         else if(pre[i]-pre[j]<0)dp[i]=max(dp[i],dp[j]+(j-i));
    //     }
    // }
//发现 dp[j]+(i-j) -->  (dp[j]-j)+i;   
    // dp[j]+(j-i) ---> dp[j]+j -i  ;
    //所以发现 只需要维护  dp[j]+j ,dp[j]-j  i 三个值
//发现对j的枚举本质上就是优化下枚举 j的代码，发现本质上就是求。
//pre[j]小于 pre[i] 时的最大值
//pre[j]等于pre[i]的最大值
//pre[j] 大于 pre[i]时的最大值
//离散化后用权值线段树 /树状数组 
//将pre[j]  的值离散化  作为下标   求区间最大值即可 



   // cout<<dp[n]<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

struct Fenwick {
    const int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n, -inf) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = std::max(a[i - 1], v);
        }
    }
    int sum(int x) {
        int ans = -inf;
        for (int i = x; i > 0; i -= i & -i) {
            ans = std::max(ans, a[i - 1]);
        }
        return ans;
    }
};
//jiangly 代码
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    auto v = s;
    std::sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        s[i] = std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();
    }
    
    Fenwick fen(n + 1);
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        fen.add(s[i - 1], dp[i - 1] - (i - 1));
        dp[i] = std::max(dp[i - 1] + (a[i - 1] < 0 ? -1 : 0), i + fen.sum(s[i]));
    }
    
    std::cout << dp[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
