#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
// 区间合并
typedef pair<int,int> PII;//默认按first sort
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
vector<PII>a;
int n;
cin>>n;
for(int i=1;i<=n;i++){
  int l,r;
  cin>>l>>r;
  a.push_back({l,r});
}
sort(a.begin(),a.end());
int ans=1;
int endd=a[0].second;
for(int i=1;i<a.size();i++){
  int l=a[i].first;
  int r=a[i].second;
  if(l<=endd&&r>endd)endd=r;
  else  if(l>endd){ans++;endd=r;}
}
cout<<ans<<endl;
    return 0;
}
