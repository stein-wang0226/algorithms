#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int mod=1e9+7;
const int N = 2e5 + 5;
int T, n, a[N];
int dp[500][40005]; //前i个回文数到达j的方案书
//方案数  完全背包
int num=0;
vector<int>pali;
vector<int>ans(50000);
bool check(int x){
    string s=to_string(x);
    string ss=s;
    reverse(ss.begin(),ss.end());
    if(ss==s)return 1;
    else return 0;
}
void solve(){
cin>>n;
cout<<ans[n]<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

for(int i=1;i<=4e4;i++){
    if(check(i))pali.push_back(i) ;
   
}
num=pali.size();

for(int j=0;j<=4e4+5;j++){
    dp[1][j]=1;
}
for(int i=2;i<=num;i++){
    for(int j=0;j<=4e4+5;j++){ //0的方案数也要算进去  否则答案差一位（n）
        dp[i][j]=dp[i-1][j]%mod;
        if(j-pali[i-1]>=0) dp[i][j]+=dp[i][j-pali[i-1]]%mod,dp[i][j]%=mod; //转移
    }
}
for(int j=1;j<=4e4+5;j++){
    ans[j]=dp[num][j]%mod;
}
//for(int i=1;i<=1000;i++)cout<<ans[i]<<endl;
cin>>T;
while(T--){
      solve();
}
  return 0;
}
