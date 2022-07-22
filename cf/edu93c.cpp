#include <bits/stdc++.h>
#define LOCAL
#define int long long
//桃园里面有 n 个人在摘桃子。现在 n 个人排成一排，从左到右每个人拥有的桃子数是 ai。
//桃园里有一个免费获得桃子的规则，如果连续 x 个人的桃子总数除以 k 的余数正好是 x, 
//那么这 x 个人就可以免费获得桃子,并且每天只有一次免费获得桃子的机会。 请聪明的你算出一共有多少种不同的方案可以使今天有人免费获得桃子。

// 将 所有a[i] %k  问题转化为 区间和模k =区间长度
//前缀和后 即 sum[j]-sum[i-1]=j - (i-1) ---> sum[j]-j=sum[i-1]-(i-1)
//map 记录所有m=sum[t]-t 个数 求C(m,2) 求和即可 m*(m-1)/2
using namespace std;
const int N=2e5+5;
int T,n,k;
int a[N],sum[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>k;
map<int,int>mp;
for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i]=(a[i])%k;
    sum[i]=(sum[i-1]+a[i]);
}
for(int i=0;i<=n;i++){
    mp[sum[i]-i]++;
}
int ans=0;
for(auto i:mp){
    int m=i.second;
    ans+=m*(m-1)/2;
}
cout<<ans<<endl;
    return 0;
}
