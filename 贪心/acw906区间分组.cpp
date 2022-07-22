#include <bits/stdc++.h>
#define endl "\n"
# pragma GCC optimize(3) 
#define LOCAL
//#define int long long
using namespace std;
//区间分组(最小)
//每个区间都要分配到不重叠的组中
//思路 设最大cnt组 将所有时间点排序  遇起始点cnt++ ,末端点cnt--;
//cnt最大值即为答案
const int N=2e5+5;
struct Node{
  int value,type;
  bool operator <(const Node&m)const{
    return value<m.value;
  }
};
int T,n;
int a[N],b[N];
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
vector<Node>vec;

cin>>n;
for(int i=1;i<=n;i++){
  cin>>a[i]>>b[i];
  vec.push_back({a[i],0});
  vec.push_back({b[i],1});  
}
int cnt=0,ans=0;
sort(vec.begin(),vec.end());
for(auto i:vec){
  if(i.type==0)cnt++,ans=max(ans,cnt);
  else cnt--;
}

cout<<ans<<endl;
    return 0;
}
