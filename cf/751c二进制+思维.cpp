#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=2e5+5;
int T,n;
// 对每个数 二进制每一位分别考虑  若所有数某一位 有m个1 则 m的因子在这一位都可为k的取值
// 求出每一位都满足的k即可  (只要对某一位的合法k值   任意取 操作最终都能将该位全变0  （只有选的k个全1才会变）)
int a[N];
int cnt[50];//每位1 的总数
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
  cin>>n;
  memset(cnt,0,sizeof cnt);
  int maxbit=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    int bit=0;
    int temp=a[i];
    while(temp){
      cnt[++bit]+=temp%2;  //累加1的个数
      temp/=2;
    }
    maxbit=max(maxbit,bit);
  }
  for(int k=1;k<=n;k++){//遍历k 取值
  int flag=1;  // 需要为所有的因子
    for(int j=1;j<=maxbit;j++){
        if(cnt[j]%k){flag=0;break;}
    }
    if(flag)cout<<k<<" ";
  }
cout<<endl;

}
    return 0;
}
