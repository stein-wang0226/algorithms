#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

int T, n,m,k;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      cin>>n>>m>>k;
      int flag=1;
      int d;
      if(n==1){
          if(m==0){
              if(k-1>0)cout<<"Yes"<<endl;
              else cout<<"No"<<endl;
          }
          else cout<<"No"<<endl;
          continue;
      }
      if(m<n-1||m>n*(n-1)/2){flag=0;cout<<"No"<<endl;continue;}
      // min()
      // 直径最小的情况
      // 发现（n-1=m）时菊花图 d=2;   ***
      //而（）完全图  d=1;
      // 所以  除完全图直径最小都为2  
        if(m==n*(n-1)/2)d=1;
        else d=2;
      if(k-1<=d)flag=0;
      if(flag)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
  }
  return 0;
}
