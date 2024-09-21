// 给定一个括号序列，要求尽可能少地添加若干括号使得括号序列变得合法，当添加完成后，会产生不同的添加结果，请问有多少种本质不同的添加结果。
// 两个结果是本质不同的是指存在某个位置一个结果是左括号，而另一个是右括号。
// 先只考虑添加左括号 之后取反反转再可得右括号 两者相乘即为答案
// 性质：在任何位置(前缀)，一个合法的括号序列都满足左括号的数量大于等于右括号的数量！
// 定义状态 ：dp[i][j]前i个括号，（比）多j个的添加方法数
// 保证不重复 eg：用）分割区间，我们只考虑在右括号的前面添加若干个左括号，因为左括号排列都一样
// 即遇到）才添加
//状态转移  遇到（ 直接加进来 因为没有右括号 f[i][j]=f[i-1][j-1]
// 遇到）f[i][j]=f[i-1][j+1]+f[i-1][j]+f[i-1][j-1]+……+f[i-1][0]
// 即在该）前每多加一个（ 相当于 之前少加一个（
//优化：f[i][j-1]=f[i-1][j]+f[i-1][j]+f[i-1][j-1]+……+f[i-1][0]，这样的话f[i][j]=f[i-1][j+1]+f[i][j-1]
// 单个 答案就是从d p ( n , 0 ) dp(n,0)dp(n,0)到d p ( n , n ) dp(n,n)dp(n,n)中的第二维最小的非0答案.
// 第二维最小的非0答案 第二维不一定取到0  可末尾用）补齐
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e3 + 5;
int dp[N][N];
string s;
const int mod = 1e9 + 7;
int n;
int get() {
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    dp[0][0]=1;
    if(s[i-1]=='('){
      for(int j=1;j<=n;j++)
        dp[i][j]=dp[i-1][j-1];
    }
    else{
            dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;//
            for(int j=1;j<=n;j++){
                dp[i][j]=(dp[i-1][j+1]+dp[i][j-1])%mod; // 已优化
              }
            }
          }
          for(int i=0;i<=n;i++){
            if(dp[n][i])return dp[n][i];
          }

          return -1;

        }

        void solve() {
          cin >> s;
          n=s.size();
          int x=get();
          reverse(s.begin(),s.end());
          for(int i=0;i<n;i++){
            if(s[i]=='(')s[i]=')';
            else s[i]='(';
          }
          int y = get();
          cout<<(x*y)%mod;
        }
        signed main() {
          std::ios::sync_with_stdio(false);
          cin.tie(0);
          cout.tie(0);
          solve();
          return 0;
        }
