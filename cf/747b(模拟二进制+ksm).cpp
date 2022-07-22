#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int T,n;
const int mod=1e9+7;
int ksm(int a,int b){
int res=1;
while(b){
  if(b&1){
    res*=a;
    res%=mod;
  }
  a=(a*a)%mod;
  b>>=1;
}
return res%mod;
}


signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
//模拟二进制   快速幂
cin>>T;
while(T--){
int k;
cin>>n>>k;
int ans=0;
for(int i=0;k>0;i++){
int m=k%2;
if(m){ans+=ksm(n,i);ans%=mod;}
k>>=1;
}

cout<<ans<<endl;
}
    return 0;
}
