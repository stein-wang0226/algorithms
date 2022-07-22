#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//思维
//题意：定义星星的等级为在它左下角（包括正左和正下）的星星的个数
//给出若干个星星的坐标，输出各个等级的星星分别有多少个
//因为已经按序排列 所以只比较x坐标即可 直接计算当前点之前横坐标小于等于X的个数
//树状数组 c[i]对应a[i]储存坐标为i的star数  每次查sum[i]前缀和  即自己等级，记录即可
//单点更新+区间查询应用
const int MAX=32005;//注意坐标大小才是对应下标范围
int t,n,c[MAX],ans[15005];
int lowbit (int x){
  return x&-x;
}
void update(int x){
  for(int i=x;i<=MAX;i+=lowbit(i)){
    c[i]++;
  }
}

int sum(int x){//前缀和  即为等级
  int ans=0;
  for(int i=x;i>0;i-=lowbit(i)){
    ans+=c[i];
  }
  return ans;
}
int main(){
  std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n){
  memset(c,0,sizeof c);
  memset(ans,0,sizeof ans);
  for(int i=1;i<=n;i++){
    int x,y;
    cin>>x>>y;
    x++;      //    由于树状数组下标从1开始 ，所以一定要++
    update(x);
  ans[sum(x)]++;//等级为sum(x)的++
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<endl;
  }
}

    return 0;
}
