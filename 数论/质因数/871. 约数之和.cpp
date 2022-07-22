#include <bits/stdc++.h>
//#define LOCAL
#define int long long
// 求约数之和  若n= a1^k1 *a2^k2 *a3^k2
//则约数之和   sum = (a1^0+a1^1+..a1^k1)*(a2^0+a2^1+..a2^k2)*...()//展开易得  排列组合问题 
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
for(auto i:prime){//ki次*a +1刚好 :1  ai+1  ai^2+ai+1..
    int m=i.second;//次数
    int t=1;
    while(m--)t=(t*i.first+1)%mod;
    ans=ans*t%mod;
}
cout<<ans%mod<<endl;

    return 0;
}
