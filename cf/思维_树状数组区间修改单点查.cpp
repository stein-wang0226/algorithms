#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5+ 5;
//从后往前
//第k位前k-1行肯定都是a[k]  求得1的总数m  后m位减1（-f(A,n)）   从后往前遍历 所以如果这位是1 那么这位a[k]肯定>=k m--  继续遍历  -(f(A,n-1))....  

int T,  a[N],c[N];
int ans[N];
int n,d[N];
int lowbit(int i){
    return i& -i;
}
void update(int i,int val){//树状数组单点修改，每次对差值更新   
    while(i<=n)d[i]+=val,i+=lowbit(i);
}
int sum(int i){//求树状数组前缀和***//求sum d[i]实现单点查询
    int ret =0;
    while(i>0){
    ret+=d[i];
    i-=lowbit(i);
    }
    return ret;
}
void  range_update(int l,int r,int x){//差分 实现区间修改
    update(l,x);update(r+1,-x);//
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
      int cnt1=0,Sum=0;
      memset(ans,0,sizeof ans);
      memset(d,0,sizeof d);
      memset(a,0,sizeof a);
      cin>>n;
      for(int i=1;i<=n;i++){
          cin>>c[i];
          a[i]=c[i]-c[i-1];
          update(i,a[i]);
          Sum+=c[i];
      }
      cnt1=Sum/n; //1的个数

for(int i=n;i>=1;i--){
    if(sum(i)>=i){
        ans[i]=1;
        range_update(i-cnt1+1,i,-1); //减去最后一列
        cnt1-- ; //前i位1的个数--
    }
}
for(int i=1;i<=n;i++){
    cout<<ans[i]<<' ';
}
cout<<endl;

  }
  return 0;
}
