#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//  已知 f(n)=a*f(n-1)+b*f(n-1)  求 S(n)为前n项平方和
//    Sn =Sn-1 +a^2*[f(n-1)]^2+2*a*b*f(n-1)*f(n-2)+b^2*[f(n-2)]^2
long long n,a,b;//
int ret[5]={0,2,1,1,1};
const int mod=10007;
struct Matrix{
   long long matrix[6][6];//开ll
}ori,res;
void init(){//矩阵初始化
memset(ori.matrix,0,sizeof ori.matrix);
memset(res.matrix,0,sizeof res.matrix);
for(int i=1;i<=4;i++){
    res.matrix[i][i]=1;
}
ori.matrix[1][1]=1;
ori.matrix[4][2]=1;
ori.matrix[1][2]=ori.matrix[2][2]=a*a;
ori.matrix[1][3]=ori.matrix[2][3]=2*b*a;
ori.matrix[1][4]=ori.matrix[2][4]=b*b;
ori.matrix[3][2]=a;
ori.matrix[3][3]=b;
}

Matrix mul(Matrix a,Matrix b){
 Matrix ret ;
 memset(ret.matrix,0,sizeof ret.matrix);
 for(int i=1;i<=4;i++){
     for(int j=1;j<=4;j++){
         for(int k=1;k<=4;k++){
             ret.matrix[i][j]+=(a.matrix[i][k])%mod*(b.matrix[k][j]%mod)%mod;
         }
     }
 }
return ret;
}

void ksm(Matrix a,int k){
    while(k){
        if(k&1)res=mul(res,a);

        a=mul(a,a);
        k>>=1;
    }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>a>>b){
    init();
    long long ans=0;
    if(n<=1)ans=n+1;//从零开始 S0=1,S1=2
    else{
        ksm(ori,n-1);
    for(int i=1;i<=4;i++){
        ans+=(ret[i]*res.matrix[1][i])%mod;
        ans%=mod;
    }
    }
    cout<<ans<<endl;


}
    return 0;
}
