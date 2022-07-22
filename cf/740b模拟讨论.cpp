#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a,b;
void solve(){
    cin>>a>>b;
    n=a+b;
    int x,y;
    x=n/2;y=n-x; //两种情况
    set<int>ans;
    for(int i=0;i<=min(x,b);i++){ //放在x的b
    if(x-i>a)continue;   //不能超范围
        int res=i+(y-(b-i)); //放在y的a
        if(res>=0)ans.insert(res);
    }
    swap(x,y);
    for(int i=0;i<=min(x,b);i++){ //放在x的b
        if(x-i>a)continue;

        int res=i+(y-(b-i)); //放在y的a
        if(res>=0)ans.insert(res);
    }
int len=ans.size();
cout<<len<<endl;
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
