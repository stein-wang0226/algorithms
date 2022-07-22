#include <bits/stdc++.h>
#define LOCAL
#define int long long
// bitset  使用
using namespace std;
const int mod=998244353; 
const int N=1e5+5;
int T,n,k,a[105];
int bitpow[70];
void init(){// 初始化2的幂
int res=1;
for(int i=0;i<=64;i++){
  bitpow[i]=res%mod;
  res<<=1;
  res%=mod;    
}
}

signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
init();
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
bitset<64>vis;  // 标记每一位1是否处理过

int ans=0;
for(int i=1;i<=n;i++){
  bitset<64>t(a[i]); // a[i]直接转化为二进制   t
  int cnt1=0,cnt0=0;   // cnt1为1的位置  cnt0为0的位置
  for(int j=0;j<k;j++){//
    if(vis[j]==0){// 未处理
      if(t[j]==1)cnt1++;
      else   cnt0++;
     }
  }
 ans+=i*((bitpow[cnt1]-1)%mod)*(bitpow[cnt0]%mod)%mod;
  ans%=mod;
  vis|=t;   // 标记1的位置
}

cout<<ans<<endl;


    return 0;
}
