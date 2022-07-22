#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

int T, n, a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


//特判0 1 2即可.
// 无1可全0
// 有1 则不能有相邻
  cin >> T;
  while (T--) {
     map<int,int>vis;
    cin>>n;
    vis.clear();
    int flag=1;
    int flag1=0,flag2=0,flag0=0;
    int flagg=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      vis[a[i]]=1;
      if(a[i]==1)flag1=1;
      if(a[i]==0)flag0=1;
      if(a[i]==2)flag2=1;
    }
    if(flag1){
      if(flag0||flag2)flag=0;
      else{
        for(auto i:vis){
          int cnt=i.first;
          if(vis.count(cnt+1)){
            flag=0;
            break;
          }
        }
      }
    }

    if(flag)cout<<"yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
