#include <bits/stdc++.h>
//# pragma GCC optimize(3) 
#define int long long
using namespace std;

const int N=1e6+5;
const int M=1e6;
//  平方差发现只要枚举 aj的因子  并且满足两因子之差为 2*a[i]
// map记录a[i]出现次数
//  倍数遍历枚举因子
int T,n,a[N];map<int,int>cnt;
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0); 


cin>>n;
for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
int ans=0;
for(int i=1;i<=M;i++){ // 因子
  for(int j=i;j<=M;j+=i){   // 倍数
       int a=i;
       int b=j/i;  //   两个因子
        int d=abs(b-a);
        if(d%2==0){
          ans+=cnt[j]*cnt[d/2];
        }
  }
}

cout<<ans/2<<endl;   // i,j可交换

    return 0;
}
