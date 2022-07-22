#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;
//考虑dp算出分解种数
//先枚举x的因子中符合条件的数
// dp[n]  记由x变为除去若干漂亮数变为n的总方法数
//dp[1]即为所求分解方案数
//但若两因子相同会重复计数
//所以  dp[n][k]=cnt 为n 上一次被k除的方案数  这样可以保证k递增来去重
// dp[n/i][i]+=dp[n][k]  (i>k)
const int N=2e5+5;
int T,n,x,d;
int check(int n){// 是否为漂亮数
  if(n%d==0&&n%(d*d)!=0)return 1;//
  return 0;
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
  cin>>x>>d;
vector<int>num;  //x中满足的漂亮数
map<pair<int,int>,int>dp;  // 防止下标过大
dp[{x,1}]=1;  //** 初始状态x,1
for(int i=1;i<=x/i;i++){  // 存因子中漂亮数  每次判断 i ,x/i  
  if(x%i==0){
      if(check(i))num.push_back(i);
      if(x!=i*i&&check(x/i))num.push_back(x/i);
  }
}
int ans=0;
while(dp.size()){
  auto cur=*prev(dp.end());// 从最后开始 pair 最大  每次拆最大的数
  int n=cur.first.first,k=cur.first.second,cot=cur.second;
  if(n==1)ans+=cot; // ***1
  for(int i:num){
    if(n%i==0&&i>=k){
      dp[{n/i,i}]+=cot;
    }
  }
  dp.erase(prev(dp.end()));
}
if(ans<=1)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}
    return 0;
}
