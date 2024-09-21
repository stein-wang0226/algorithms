#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
const int inf = 1e18;
int n,d,k;
struct log{
  int ts,id;
  bool operator<(const log&b)const{
    return ts<b.ts;
  }
}logs[N];
map<int,vector<int>>times;
//对每个id 要找到最紧密的一段：记录位置全部tims[]  minn=min{tims[i+5]-tims[i]} 比较是否小于D即可
signed main(){
  cin>>n>>d>>k;
  for(int i=1;i<=n;i++)cin>>logs[i].ts>>logs[i].id;

    sort(logs+1,logs+1+n);

  for(int i=1;i<=n;i++){
    times[logs[i].id].push_back(logs[i].ts);
  }

  set<int>ans;

    for(auto &it:times){// 两个循环但是ts总数为N O(N)
      int idx = it.first;
      auto tims = it.second;
      int minn = inf;
      for(int i=0;i<(int)tims.size()-k+1;i++){
        minn=min(minn,tims[i+k-1]-tims[i]);
      }
      if(minn<d)ans.insert(idx);
    }


    for(auto i:ans)cout<<i<<endl;


  }