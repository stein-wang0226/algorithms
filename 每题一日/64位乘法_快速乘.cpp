#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
#define int long long
// 64位乘法取余
//快速乘
using namespace std;

const int N=2e5+5;
int T,n;
int a,b,p;
int qmul(int a,int b){
int res=0;
  while(b){
    if(b&1)res=(res+a)%p;
  
  a=a*2%p;
  b>>=1;
  }
  return res%p;
}



signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

cin>>a>>b>>p;

int ans=qmul(a,b);
cout<<ans<<endl;
    return 0;
}
