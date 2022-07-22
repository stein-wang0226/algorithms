#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
// 推导  q+k<=ti<=q+k+ci;
//  ti-(ci-1)-k<=q<=ti-k
//区间修改？
const int N = 2e6 + 5;
int m,k, n, a[N];//a初值0
struct segtreenode{
  int val;
  int lazy ;//懒惰标记  
       //其他元素
}segtree[N<<2];//定义原数组大小四倍的线段数组
void pushup(int rt){
  segtree[rt].val=segtree[rt<<1].val+segtree[rt<<1|1].val;//线段树写法
}//将左右字数的总值加到根节点
void build(int l,int r,int rt){// 递归构造线段树
  segtree[rt].lazy=0;//     初始化
  if(l==r){//出口  左右相等 为叶子节点则停止向下递归
      segtree[rt].val=a[l];//叶子节点的l,r即位置下标
      return;
  }
  int mid=(l+r)/2;
  build(l,mid, rt*2);   //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid+1,r,rt*2+1);  //递归构造右子树
  pushup(rt);           //** 回溯,当左右子树都构造完后向上加到根节点
}
//ln,rn 分别为左右子区间大小
void pushdown(int rt,int ln,int rn){
  if(segtree[rt].lazy){//有懒惰标记
    segtree[rt<<1].lazy+=segtree[rt].lazy;//更新左右子区间的值和懒惰标记
    segtree[rt<<1|1].lazy+=segtree[rt].lazy;
    segtree[rt<<1].val+=segtree[rt].lazy*ln;
    segtree[rt<<1|1].val+=segtree[rt].lazy*rn;
    segtree[rt].lazy=0;//** 清除标记
  }
}
//区间更新-->延迟操作 ***(eg. a[L,R]+=c)  [L,R]为操作区间,[l,r]为当前区间，rt为节点编号
// 结果：将完全包含于[L,R]的子区间更新并存lazy，其余等查询后再下推
void updateRange(int L,int R,int l,int r,int c,int rt){
    if(L<=l&&r<=R){//只有当前区间被完全包含才更新自己及子区间  ,部分包含先不更新，减少操作次数   
        segtree[rt].val+=c*(r-l+1);     //更新区间总和
        segtree[rt].lazy+=c;     //根据不同操作更新懒惰标记  
        return ;
    }
    int mid=(l+r)/2;
    //只做了lg级的pushdowm，其余用懒惰记录，查询时修改
    pushdown(rt,mid-l+1,r-mid);// 一次下推操作，才能准确 更新左右子节点 (非必要，不下退)
    if(L<=mid) updateRange(L,R,l,mid,c,rt<<1);//更新左子区间
    if(R>mid) updateRange(L,R,mid+1,r,c,rt<<1|1);   //更新右子区间
    pushup(rt);
}

//区间更新的区间查询（单点）
int queryRange(int L,int R,int l,int r,int rt){//L,R 为全区间
  if(L<=l&&r<=R)   
    return  segtree[rt].val;

  if(L>r||R<l)    
  return 0;

  int mid=(l+r)>>1;
  pushdown(rt,mid-l+1,r-mid);//唯一不同,也是精华所在 ，查询到，必要时下推
  return  queryRange(L,R,l,mid,rt<<1)+queryRange(L,R,mid+1,r,rt<<1|1);
}
void solve(){
    cin>>n>>m>>k;
        build(1,N,1);
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++){
        int t,c;
        cin>>t>>c;
        int l=t-(c-1)-k,r=t-k;
        if(r>0)updateRange(max(1ll,l),r,1,N,1,1);//
    }
    for(int i=1;i<=m;i++){
        int q;
        cin>>q;
        int ans=queryRange(q,q,1,N,1);
        cout<<ans<<endl;
    }

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
      solve();
  
  return 0;
}
