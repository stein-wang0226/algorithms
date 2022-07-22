#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
const int MAX =1e5+5;
int a[MAX],b[MAX],n;
//整数 拆分 ：模拟母函数  (1+x+x^2+x^3+...)(1+x^2+x^4+..)()...
//a,b 分别储存 前后两个乘式各项系数(下标代表次数***)
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while (cin>>n){//不需每次计算
 memset(a,0,sizeof a);
 memset(b,0,sizeof b);
  
 for(int i=0;i<=n;i++){//此题中第一个乘式每个次数系数为0.
   a[i]=1;
 }

 for(int i=2;i<=n;i++)//循环次数:共n-2次乘法
{
  for(int j=0;j<=n;j++){//每次前一个乘式 前n次系数
        for(int k=0;k+j<=n;k+=i){//后一个式子系数（每次加i）
        b[j+k]+=a[j];
        }
  }
  for(int i=0;i<=n;i++){
    a[i]=b[i];//结果返回a
    b[i]=0;//b清空用于接收下一次结果
  }
}
cout<<a[n]<<endl;

}


    return 0;
}
