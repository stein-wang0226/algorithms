#include <bits/stdc++.h>
//#define LOCAL
#define int long long
//输出一个整数，表示所给正整数的乘积的约数个数，答案需对 109+7 取模。
//  求约数个数    求出每个因子个数  a1,a2,a3..  sum=(a1+1)(a2+1)(a..+1)//排列
using namespace std;
const int mod=1e9+7;
int T,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
unordered_map<int,int>prime;//映射存 质数i的次数
while(T--){//每次同样操作即可
cin>>n;
for(int i=2;i<=n/i;i++){//试除法
    while(n%i==0)n/=i,prime[i]++;
}    
if(n>1)prime[n]++;   //
}
int ans=1;
for(auto i:prime){
    ans=ans*(i.second+1)%mod;
    ans%=mod;
}
cout<<ans<<endl;

    return 0;
}
