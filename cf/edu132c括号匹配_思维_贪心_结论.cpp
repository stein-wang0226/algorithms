#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
// 括号序列相关结论 ：假设遇到左括号 cnt+1，右括号cnt-1 ，则若合法则cnt一定=0,**且中途没有<0的时候
// 故左边（ 越多越好
// 计算除？外cnt数  和？数wh  
// 当 cnt+wh==1  必定 前面全匹配且最后一个为（，故将wh=0**
// 唯一：最后一定有 abs(cnt)==wh  多余wh填补cnt   
const int N = 2e5 + 5;
int T, n, a[N];
void solve(){
    string s;
    cin>>s;
    int cnt=0;
    int wh =0;
    for(auto c:s){
        if(c=='(')cnt++;
        else if(c==')')cnt--;
        else wh++;
        if(wh+cnt==1){
            cnt=1;
            wh=0;
        }
    }
    if(abs(cnt)==wh)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
