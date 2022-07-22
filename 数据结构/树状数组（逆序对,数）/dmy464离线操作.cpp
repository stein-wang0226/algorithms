#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int N=1e5+5;
int T;
#define int long long
//在给定 N 长的数组 {A} 中进行 Q 次询问 [Li,Ri] 区间中不大于 Hi 的元素个数。
// 离线 存询问 从小到大  开长度为n的01区间(开始全0) 每次将小于每次询问将小于=hi 的变1 否则仍为0  区间求和
int c[N],n,q;
int a[N];
int ans[N];
struct Node{
  int id,l,r,h;
  bool operator<(const Node&b){
    return h<b.h;
  }
};  // 储存查询操作
int lowbit(int x){
    return x& -x;
}
void update(int i,int val){
    while(i<=n+1){    // 这里要+1 不知道为啥
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i){//求前缀和
    int ret =0;
    while(i>0){
        ret+=c[i];
        i-=lowbit(i);
    }
    return ret;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
  memset(c,0,sizeof c);
cin>>n>>q;
vector<Node>Q; // 存查询
vector<pair<int,int>>S;  // 
for(int i=1;i<=n;i++){cin>>a[i];S.push_back({a[i],i});}  //存值和原位置
sort(S.begin(),S.end());
for(int i=1;i<=q;i++){
  int l,r,h;
  cin>>l>>r>>h;
  Q.push_back({i,l,r,h});
}
sort(Q.begin(),Q.end());
int pos=0;//
for(auto i:Q){
  int hi=i.h;
  for(int j=pos;j<n;j++){// 下一次从pos+1开始
  if(S[j].first>hi)break;
    if(S[j].first<=hi){  // 小于的a[i]从小到大更新
      update(S[j].second,1);    //  对应a[i]位置更新1
    }
    pos=j+1;  // 不要重复更新
  }
int l=i.l,r=i.r;
// cout<<sum(r)<<" "<<sum(l-1)<<endl;;
ans[i.id]=sum(r)-sum(l-1);
}


for(int i=1;i<=q;i++){
  cout<<ans[i]<<" ";
}
cout<<endl;

}
    return 0;
}
