#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 3e5 + 5;
//线段树 +差分 倒序遍历 区间修改
//考虑到 减去一个等差数列等价于 加上[-1，1...]的前缀和
//那么将整个数组差分 则减去等差数列的差分数组等价于  指定差分数组区间都-1
// 那么对差分数组线段树区间修改即可
int T, n, a[N];
int d[N]; //差分
int k;
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
      segtree[rt].val=d[l];//叶子节点的l,r即位置下标
      return;
  }
  int mid=(l+r)/2;
  build(l,mid, rt*2);   //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid+1,r,rt*2+1);  //递归构造右子树
  pushup(rt);           //** 回溯,当左右子树都构造完后向上加到根节点
}
void pushdown(int rt,int ln,int rn){
  if(segtree[rt].lazy){//有懒惰标记
    segtree[rt<<1].lazy+=segtree[rt].lazy;//更新左右子区间的值和懒惰标记
    segtree[rt<<1|1].lazy+=segtree[rt].lazy;
    segtree[rt<<1].val+=segtree[rt].lazy*ln;
    segtree[rt<<1|1].val+=segtree[rt].lazy*rn;
    segtree[rt].lazy=0;//** 清除标记
  }
}
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
int queryRange(int L,int R,int l,int r,int rt){
  if(L<=l&&r<=R)   
    return  segtree[rt].val;

  if(L>r||R<l)    
  return 0;

  int mid=(l+r)/2;
 pushdown(rt,mid-l+1,r-mid);//唯一不同,也是精华所在 ，查询到，必要时下推
  return  queryRange(L,R,l,mid,rt<<1)+queryRange(L,R,mid+1,r,rt<<1|1);
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
a[0]=d[0]=0;
for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];  //对差分数组处理
build(1,n,1);
int ans=0;
for(int i=n;i>0;i--){
    int num=queryRange(1,i,1,n,1); //差分前缀和得a[i]的当前值
    if(num>0){
        int L=max(1ll,i-k+1); //左端点
        int R=L+k-1; //
        int cnt=i-L+1;//一次可减去长度
        int tim=ceil(1.0*num/cnt);  //向上取整 避免分类  
    updateRange(L,R,1,n,-tim,1);  //差分区间更新
    ans+=tim;
    }
}

cout<<ans<<endl;
return 0;
}
