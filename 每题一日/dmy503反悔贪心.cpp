#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
#define int long long
using namespace std;


//反悔贪心  因为完成时间都为1 所以只需贪心取p最大即可
//按截至时间排序 遍历元素能放就放 不能放比较队中最小的交换 小的被舍弃 
//用优先队列维护利润（小顶堆）
const int N=2e5+5;
priority_queue<int,vector<int>,greater<int>>que;
struct Node{
  int d,p;
  bool operator <(const Node&b ){
    return d<b.d;
  }
}p[N];
int T,n;
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){
  cin>>p[i].d>>p[i].p;
}
sort(p+1,p+1+n);
for(int i=1;i<=n;i++){  // 能放入直接放
if(p[i].d<=0)continue;
  if(p[i].d>que.size()){
    que.push(p[i].p);
  }
  else if(p[i].p>que.top()){// 与堆顶比较
    que.pop();   // 舍弃堆顶  肯定不会放入(截至早且价值低)
    que.push(p[i].p);
  }
}
int ans=0;
while(!que.empty()){
  ans+=que.top();
  que.pop();
}


cout<<ans<<endl;
    return 0;
}
