#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//  九连环递推式  Fn=F(n-1)+2F(n-2)+1    含常数的矩阵构造
int n;
int ret[4]={0,2,1,1};
const int mod= 200907;
struct Matrix{
   long long matrix[5][5];//开ll
}ori,res;
void init(){//矩阵初始化
memset(ori.matrix,0,sizeof ori.matrix);
memset(res.matrix,0,sizeof res.matrix);
for(int i=1;i<=3;i++){
    res.matrix[i][i]=1;
}
ori.matrix[1][1]=ori.matrix[1][3]=1;
ori.matrix[1][2]=2;
ori.matrix[2][1]=ori.matrix[3][3]=1;
}

Matrix mul(Matrix a,Matrix b){
 Matrix ret ;
 memset(ret.matrix,0,sizeof ret.matrix);
 for(int i=1;i<=3;i++){
     for(int j=1;j<=3;j++){
         for(int k=1;k<=3;k++){
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
while(cin>>n,n){
    init();
    long long ans=0;
    if(n<=2)ans=n;
    else{
        ksm(ori,n-2);
    for(int i=1;i<=3;i++){
        ans+=(ret[i]*res.matrix[1][i])%mod;
        ans%=mod;
    }
    }
    cout<<ans<<endl;


}
    return 0;
}
