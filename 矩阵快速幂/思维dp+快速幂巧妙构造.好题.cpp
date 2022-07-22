#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//长度为n的01串超过2个连续相同的个数
//二维 dp
/* dp[i][j]表示前i个硬币最后j个是连续的。***重难点
那么dp[i][j]只有两种转移方法：dp[i+1][j+1],dp[i+1][1];
因为长度一旦超过2，我们就可以确定这个排列是符合要求的，后面的任何一位不管是正面还是反面都满足要求，所以就可以算出dp[i][3]*2^(n-i);
一旦出现了连续三个就可以满足这个式子。
dp[i][3]=dp[i-1][2];//必须前两个连续，再放一种相同的
dp[i][2]=dp[i-1][1];//必须再放一种相同的
dp[i][1]=dp[i-1][1]+dp[i-1][2];//i和i-1不同但i-2有两种情况
                dp[1][1]=2;dp[1][2]=0;dp[1][3]=0;
这里我们引入多一列dp[i][4]记录前面满足条件的总数；   //是前i-1位的总数****
dp[i][4]=dp[i-1][3]+dp[i-1][4]*2    ***（这里乘2，就是前面满足条件的排列在第i位可以任意放）
         */
//然后  dp[i][4]~dp[i][1]构造矩阵
const long long mod=10007;
long long  n;
int dp[5]={0,0,0,0,2};//对应dp[1][]的值
struct Matrix{
  long long Matrix[5][5];
}ori,res;

void init(){
memset(ori.Matrix,0,sizeof ori.Matrix);
memset(res.Matrix,0,sizeof res.Matrix);
for(int i=1;i<=4;i++){
  res.Matrix[i][i]=1;
}
ori.Matrix[1][2]=ori.Matrix[2][3]=ori.Matrix[3][4]=ori.Matrix[4][3]=ori.Matrix[4][4]=1;
ori.Matrix[1][1]=2;
}

Matrix mul(Matrix a,Matrix b){
  Matrix ret;
  memset(ret.Matrix,0,sizeof ret.Matrix);
  for(int i=1;i<=4;i++){
    for(int j=1;j<=4;j++){
      for(int k=1;k<=4;k++){
        ret.Matrix[i][j]+=((a.Matrix[i][k]%mod)*(b.Matrix[k][j]%mod))%mod;
      }
    }
  }
return ret;
}

void ksm(Matrix a,long long k){
  while(k){
    if(k&1) res=mul(res,a);

    a=mul(a,a);
    k>>=1;
  }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n){
if(n<=2){cout<<"0"<<endl;continue;}
init();
ksm(ori,n);//因为dp[4]储存的是i-1位的答案所以 n-1+1
long long ans=0;
for(int i=1;i<=4;i++){
  ans+=((res.Matrix[1][i]%mod)*dp[i])%mod;
  ans%=mod;
}
cout<<ans<<endl;
}
    return 0;
}
