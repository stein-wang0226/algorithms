#include<bits/stdc++.h>
#define LL long long
using namespace std;

//对于连续的多个1来说，有效的移动是成对的11，单独多出来的那个是无法移动的。(相对于0)***
//问题就传化成了有cnt0个0,cnt1个11，有几种方案数。
//c[cnt0+cnt1][cnt0]
const int mod =998244353;
const int N=1e5+5;
int n,a,b,T;
int fact[N],infact[N];
LL qpow(int a,int k){
LL res=1;
    while(k){
        if(k&1)res=res*a%mod;
        a=(LL)a*a%mod;
        k>>=1;
    }
    return res%mod;
}
LL cal(int a,int b){
	LL res=(LL)(LL)fact[a]*infact[b]%mod*infact[a-b]%mod;
	return res;
}
int main(){
      freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++){//预处理阶乘
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i]=(LL)infact[i-1]*qpow(i,mod-2)%mod;
        //费马小定理 (mod为质数)
    }
    cin>>T;
    while(T--){
      int cnt0=0,cnt1=0; // 0和成对1 个数
      cin>>n;
      string s;
      cin>>s;
      int temp=0;
      for(int i=0;i<s.size();i++){
          if(s[i]=='1')temp++;
          else {
            cnt1+=temp/2;
            temp=0;
            cnt0++;
          }
      }
      cnt1+=temp/2 ; // 不要漏了末尾可能非0
//求 C
a=cnt0+cnt1;
b=cnt0;
  LL ans=cal(a,b);
        cout<<ans<<endl;
        }
    return 0;
}