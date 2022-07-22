#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
// 考虑每一段0之间的区间
// 如果位正，则直接取
//如果为负找第一个和最后一个负数分割的区间
const int N = 2e5+ 5;

int T, n, a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    cin>>n;
    vector<int>z;//0
    z.push_back(0);
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]==0)z.push_back(i);
    }
    z.push_back(n+1);
    int len=z.size();
    int maxx=0;
    int ml=1,mr=0;
    for(int i=0;i<z.size()-1;i++){
      int l=z[i]+1,r=z[i+1]-1;
      int cnt2=0,s=1;
      for(int i=l;i<=r;i++){
        if(abs(a[i])==2)cnt2++;
        if(a[i]<0)s*=(-1);
      }
      if(s>0){
        if(cnt2>maxx){
          maxx=cnt2;
          ml=l,mr=r;
        }
      }
        else{
          int pos1,pos2;
          int cnt0=0,cnt1=0;
          for(int i=l;i<=r;i++){
            if(a[i]<0){pos1=i;break;}
            if(abs(a[i])==2)cnt0++;
          }
          if(abs(a[pos1])==2)cnt1=cnt2-cnt0-1;
          else cnt1=cnt2-cnt0;
          if(cnt0>maxx){
            maxx=cnt0;
            ml=l,mr=pos1-1;
          }
          if(cnt1>maxx){
            maxx=cnt1;
            ml=pos1+1,mr=r;
          }
          cnt0=0;
          for(int i=r;i>=l;i--){
            if(a[i]<0){pos2=i;break;}
            if(abs(a[i])==2)cnt0++;
          }
          if(abs(a[pos2])==2)cnt1=cnt2-cnt0-1;
          else cnt1=cnt2-cnt0;
          if(cnt0>maxx){
            maxx=cnt0;
            ml=pos2+1,mr=r;
          }
          if(cnt1>maxx){
            maxx=cnt1;
            ml=l,mr=pos2-1;
          }
        
        }
    }
    cout<<ml-1<<" "<<n-mr<<endl;
  }
  return 0;
}
