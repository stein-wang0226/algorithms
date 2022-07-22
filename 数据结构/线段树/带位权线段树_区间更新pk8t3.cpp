#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
#define int long long
using namespace std;
const int mod=19260817 ;
const int MAX=2e5+5;
// 考虑到位权值固定   建树时计算区间总权值  来修改区间加权总价值
// 区间更新 区间加权和sum    查讯直接返回seg[1].sum即可 
//  线段树结点维护区间权值和(一次修改整个区间)   区间加权总和
// 所求为整个区间的答案  只要查 第一个结点tree[1].sum 即可  不用区间更新
int T,n,p,m;
int a[MAX];//原数组 可不用
int qpow(int a,int k){
  int res=1;
  while(k){
    if(k&1)res=res*a%mod;
    k>>=1;
    a=a*a%mod;
  }
  return res%mod;
}
struct segnode{
  int val;   // 区间位权值和
  int sum;   // 位全值*位上的值  即区间答案数值
  int lazy ;//懒惰标记  
}seg[MAX<<2];//定义原数组大小四倍的线段数组
void pushup(int rt){ // 
  seg[rt].val=(seg[rt<<1].val+seg[rt<<1|1].val)%mod;//区间位权值和
  seg[rt].sum=(seg[rt<<1].sum+seg[rt<<1|1].sum)%mod;//区间加权值
}

void build(int l,int r,int rt){// 递归构造线段树
  seg[rt].lazy=0;//     初始化
  if(l==r){//出口  左右相等 为叶子节点则停止向下递归
      seg[rt].val=qpow(p,n-l);//叶子结点 位权值
      seg[rt].sum=seg[rt].val*a[l]%mod; //加权值
      return;
  }
  int mid=(l+r)/2;
  build(l,mid, rt*2);   //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid+1,r,rt*2+1);  //递归构造右子树
  pushup(rt);           //** 
}
void pushdown(int rt,int ln,int rn){
  if(seg[rt].lazy){//有懒惰标记
    seg[rt<<1].lazy=seg[rt].lazy;//更新左右子区间的值和懒惰标记
    seg[rt<<1|1].lazy=seg[rt].lazy;
// 下推更新
    seg[rt<<1].sum=seg[rt].lazy * seg[rt<<1].val%mod;  // 权值乘区间改变成的数值 更新
    seg[rt<<1|1].sum=seg[rt].lazy * seg[rt<<1|1].val%mod;
    seg[rt].lazy=0;//** 清除标记
  }
}

void updateRange(int L,int R,int l,int r,int c,int rt){
    if(L<=l&&r<=R){//只有当前区间被完全包含才更新自己及子区间  ,部分包含先不更新，减少操作次数   
        seg[rt].sum=seg[rt].val*c%mod;    //更新区间每位的值
        seg[rt].lazy=c;               //更新懒惰标记  
        return ;
    }
    int mid=(l+r)/2;
    //只做了lg级的pushdowm，其余用懒惰记录，查询时修改
    pushdown(rt,mid-l+1,r-mid);// 下推时计算更新sum
    if(L<=mid) updateRange(L,R,l,mid,c,rt<<1);//更新左子区间
    if(R>mid) updateRange(L,R,mid+1,r,c,rt<<1|1);   //更新右子区间
    pushup(rt); //向上更新
}


signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif


cin>>n>>p;
for(int i=1;i<=n;i++)cin>>a[i];
build(1,n,1);
cin>>m;
int l,r,x;
for(int i=1;i<=m;i++){
  cin>>l>>r>>x;
  updateRange(l,r,1,n,x,1);
  cout<<seg[1].sum<<endl;
}


    return 0;
}
