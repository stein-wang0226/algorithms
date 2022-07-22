#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
//#define int long long

// lis 二分优化  nlogn
// 考虑 dp[i]表示长度为i的上升子序列中最后一个元素最小值，
//len 表示当前最大长度
//显然dp递增 二分查找
using namespace std;

const int N=2e5+5;

int T,n;
int a[N];
int dp[N];
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

int len=0;
for(int i=1;i<=n;i++){  // a[i]可以接在最大长度len的后面 ，则len++,同时更新
    if(dp[len]<a[i])dp[++len]=a[i];
    else{
        int pos=lower_bound(dp+1,dp+1+n,a[i])-dp;
        dp[pos]=a[i];//   更新dp[]
    }
}
cout<<len<<endl;
    return 0;
}
