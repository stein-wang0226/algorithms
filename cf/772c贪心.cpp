#include <bits/stdc++.h>
#define LOCAL
#define int long long
//772c   最后两个无法改变  所以只能a[n]>a[n-1]满足
//***如果最后一个数小于0   则之前全为负---只可能原先全部递减或递增、
//否则只需要全用 a[n]-a[n-1]代替即可  （构造）
using namespace std;
const int N=2e5+5;
int T,n;
int a[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
  cin>>n;

for(int i=1;i<=n;i++)cin>>a[i];
if(a[n]<a[n-1]){cout<<"-1"<<endl;continue;}

if(a[n]<0){
  if(is_sorted(a+1,a+n+1)){
    cout<<0<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
}
else{
  cout<<n-2<<endl;
  for(int i=1;i<=n-2;i++){
    cout<<i<<" "<<n-1<<" "<<n<<endl;
  }



}

}
    return 0;
}
