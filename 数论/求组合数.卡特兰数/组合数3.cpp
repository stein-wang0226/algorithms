#include<bits/stdc++.h>
#define int long long//
using namespace std;
// a,b 范围大  lucas定理将Ca,b 递归拆分 至p以内 直接计算C
const int N=1e5+5;
int n,a,b,p;
int qpow(int a,int k){
    int res=1;
    while(k){
        if(k&1)res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}

int C(int a,int b){
    if(b>a)return 0;
    int  res=1;
    int temp=1;
    for(int i=a,j=1;j<=b;i--,j++)
    {
        res=res*i%p;     //计算a*...*b
        temp=temp*j%p;    //  计算b!
    }
    return res*qpow(temp,p-2)%p;//      逆元 费马  除变乘  算/b!
}

int lucas(int a,int b){//lucas  缩小 a,b 规模  C(a,b)同余 C(a%p,b%p)*C(a/p,b.p)
    if(a<p&&b<p)return C(a,b);//   小于
    return  lucas(a%p,b%p)*lucas(a/p,b/p)%p;
}
signed main(){
    cin>>n;
    while(n--){
        cin>>a>>b>>p;
        cout<<lucas(a,b)<<endl;;
    }
  
    return 0;
}