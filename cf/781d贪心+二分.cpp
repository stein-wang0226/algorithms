#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
vector<int>vec;
int check(int x){
    int last=x-vec.size()-1; //第一步剩下的时间可做操作2
    for(int i=0;i<vec.size();i++){
        if(vec[i]>x-i){//消耗第一步   x-i:第i+1个在第i秒才被感染
            last-=(vec[i]-(x-i));
        }
        if(last<0)return 0;
    }
return 1;
}
int T, n, a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      map<int,int>cnt;  //孩子数 非叶子
      cin>>n;
      int m;
      for(int i=1;i<n;i++){
            cin>>m;
            cnt[m]++;
      }
      vec.clear();
      for(auto i:cnt)
      {
            vec.push_back(i.second);
      }
      sort(vec.begin(),vec.end(),greater<int>());
        //肯定是先将每个父节点的孩子都染一次 然后再染未感染d
             //二分 之后额外时间
        int l=0,r=2e5+5;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
  } 
  return 0;
}
