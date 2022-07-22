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
  cin >> T;
  while (T--) {
      cin>>n;
      vector<int>b,v;
      int ans=1;
      int flag=0;
      for(int i=1;i<=n;i++){  // 将1拿到最前面
        cin>>a[i];
        if(a[i]==1)flag=1;
        if(!flag)b.push_back(a[i]);
        else v.push_back(a[i]);
      }
      for(auto i:b)v.push_back(i);
      int cnt=0;
      int len=v.size();
      for(int i=0;i<len;i++){
          if(v[i]==1)cnt++;
          if(cnt>1){ans=0;break;}
          if(i&&v[i]-v[i-1]>1)ans=0;
          if(!ans)break;
      }
      if(cnt!=1)ans=0;
      if(ans)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
  }
  return 0;
}
