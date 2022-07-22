#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;
// dp[] +二分 同lis
//dp[i]为以i结尾**的子序列的最长长度
// 直接  dp[i]=max(dp[i-1]+1)
const int N=2e5+5;
map<int,int>dp;
int a[N];
int T,n;
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int maxx=0; //记录最大长度
int last;// 最后元素
//初始长度为0
for(int i=1;i<=n;i++){
  dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);  
  if(dp[a[i]]>maxx){
    maxx=dp[a[i]];
    last=a[i];
  }
  else if(dp[a[i]]==maxx){   // 维护字典序最小
    last=min(last,a[i]);
  }
}
cout<<maxx<<endl;
for(int i=last-maxx+1;i<=last;i++){
  cout<<i<<" ";
}
cout<<endl;



    return 0;
}
