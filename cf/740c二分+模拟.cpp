#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
//先将每个洞穴 通关的最小初始能量求出 再二分答案从小到大check
int T, n;
int k[N];   // 
int ini[N];  //最小初始能量
struct node{
    int id,val;
    bool operator <(const node&b)const{
        return val<b.val;
    }
}p[N];

int check(int x){
    int cur=x;
    int flag=1;
    for(int i=1;i<=n;i++){
        if(cur>p[i].val){
            cur+=k[p[i].id];
        }
        else{
            flag=0;break;
        }
    }
    return flag;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];    //
    vector<int> a;  //怪的血量
    int tt;
    for (int j = 1;  j<= k[i]; j++) {
      cin >> tt;
      a.push_back(tt);
    }
    int maxx = 0;
    for (int j = 0; j < a.size(); j++) {
      maxx = max(maxx, a[j] - j);  //最大初始值
    }
    ini[i]=maxx;
  }
for(int i=1;i<=n;i++){
    p[i].id=i;
    p[i].val=ini[i];
}
sort(p+1,p+1+n);

int l=0,r=2e9;
while(l<r){
    int mid=(l+r)>>1;
    if(check(mid))r=mid;
    else l=mid+1;
}
cout<<l<<endl;
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
