#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX=200005;
int m,n,a[MAX];
//单点修改，区间求最值--->将求和变为最大值即可
struct segtreenode{
  int val;
       //其他元素
}segtree[MAX<<2];//定义原数组大小四倍的线段数组

void build(int l,int r,int rt){// 递归构造线段树
  if(l==r){//出口  左右相等 为叶子节点则停止向下递归
      segtree[rt].val=a[l];//叶子节点的l,r即位置下标
      return;
  }
  int mid=(l+r)/2;
  build(l,mid, rt*2);   //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid+1,r,rt*2+1);  //递归构造右子树
 segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val)  ;    //此处存的最大值而非和 ****    //** 回溯,
}

//单点更新 类似二进制，每层只需更新一个  从上到下
void updateNode(int t,int c,int l,int r,int rt){//l,r 表示当前节点区间，rt表示当前根节点编号
  if(l==r){//序号为t的节点
    segtree[rt].val=c;
    return;
  }
  int mid=(l+r)/2;
  if(t<=mid)  updateNode(t,c,l,mid,rt<<1);  //更新左子树
  else    updateNode(t,c,mid+1,r,rt<<1|1);
 segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val)  ;                       //回溯向上更新，相加
}
int querymax(int L,int R,int l,int r,int rt){
  if(L<=l&&r<=R)   
    return  segtree[rt].val;//当前区间被包含 则直接返回(整个被加)
  // 并且不再向下递归
  if(L>r||R<l)    //当前区间全部不重和，则返回0，而且其子区间也不会包含
  return -1;
//否则部分包含  向下递归
  int mid=(l+r)/2;
  return  max(querymax(L,R,l,mid,rt<<1),querymax(L,R,mid+1,r,rt<<1|1));
}


int main(){
//   std::ios::sync_with_stdio(false);
// cin.tie(0); 
// cout.tie(0);

#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m){
  memset(a,0,sizeof a);
for(int i=1;i<=n;i++){
  cin>>a[i];
}
build(1,n,1);
while(m--){
  char c;int a,b;
  cin>>c>>a>>b;
  if(c=='U'){//单点更新
    updateNode(a,b,1,n,1);
  }
  else if(c=='Q'){//区间查询最大值
  int ans=querymax(a,b,1,n,1);
  cout<<ans<<endl;
  }
}


}
    return 0;
}
