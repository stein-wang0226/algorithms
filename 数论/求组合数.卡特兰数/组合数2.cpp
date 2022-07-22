#include<bits/stdc++.h>
#define LL long long
using namespace std;
//a,b 范围大 预处理阶乘 逆元 阶乘
// 注意 long long
const int mod =1e9+7;
const int N=1e5+5;
int n,a,b;
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
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++){//预处理阶乘
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i]=(LL)infact[i-1]*qpow(i,mod-2)%mod;
        //费马小定理 (mod为质数)
    }
    cin>>n;
    while(n--){
        cin>>a>>b;
        //LL ans=(LL)fact[a]*infact[b]%mod*infact[a-b]%mod;
        LL ans=cal(a,b);
        cout<<ans<<endl;
        }
    return 0;
}
