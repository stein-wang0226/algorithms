#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//807e
//  类比二进制 每个数k代表二进制第k位
// 所求即为最高位 位数
// 修改a b  即a位-1，b位+1；
// 数字太大 考虑01串操作  ：从低位到高位：从左到右（反转）
//第k位 +1：找到该位及左边第一个0变1，在将该位与该0之间的1变0即可          -1同理
// 区间修改求和++查询位置
const int N = 3e5+ 5;
int T, n,q, a[N];
int bits[N];
struct segtreenode{
  int val;
  int lazy ;//懒惰标记  
       //其他元素
}segtree[N<<2];//定义原数组大小四倍的线段数组
void pushup(int rt){
  segtree[rt].val=segtree[rt<<1].val+segtree[rt<<1|1].val;//线段树写法
}//将左右字数的总值加到根节点

void build(int l,int r,int rt){
  segtree[rt].lazy=0;//     初始化
  if(l==r){
      segtree[rt].val=bits[l];
      return;
  }
  int mid=(l+r)/2;
  build(l,mid, rt*2);   //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid+1,r,rt*2+1);  //递归构造右子树
  pushup(rt);           //** 回溯,当左右子树都构造完后向上加到根节点
}
void pushdown(int rt,int ln,int rn){
  if(segtree[rt].lazy){//鏈夋噿鎯版爣璁?
    segtree[rt<<1].lazy+=segtree[rt].lazy;//鏇存柊宸﹀彸瀛愬尯闂寸殑鍊煎拰鎳掓儼鏍囪
    segtree[rt<<1|1].lazy+=segtree[rt].lazy;
    segtree[rt<<1].val+=segtree[rt].lazy*ln;
    segtree[rt<<1|1].val+=segtree[rt].lazy*rn;

    segtree[rt].lazy=0;//** 娓呴櫎鏍囪
  }
}
void updateRange(int L,int R,int l,int r,int c,int rt){
    if(L<=l&&r<=R){
        segtree[rt].val+=c*(r-l+1);     //鏇存柊鍖洪棿鎬诲拰
        segtree[rt].lazy+=c;     //鏍规嵁涓嶅悓鎿嶄綔鏇存柊鎳掓儼鏍囪  
        return ;
    }
    int mid=(l+r)/2;
    pushdown(rt,mid-l+1,r-mid);
    if(L<=mid) updateRange(L,R,l,mid,c,rt<<1);//鏇存柊宸﹀瓙鍖洪棿
    if(R>mid) updateRange(L,R,mid+1,r,c,rt<<1|1);   //鏇存柊鍙冲瓙鍖洪棿
    pushup(rt);
}
int queryRange(int L,int R,int l,int r,int rt){
  if(L<=l&&r<=R)   
    return  segtree[rt].val;
  if(L>r||R<l)    
  return 0;
  int mid=(l+r)/2;
  pushdown(rt,mid-l+1,r-mid);//
  return  queryRange(L,R,l,mid,rt<<1)+queryRange(L,R,mid+1,r,rt<<1|1);
}
//  ****重点******
int query0(int L,int l,int r,int rt){ //找l右边第一个0   l为查找位置
  if(r<L||segtree[rt].val==r-l+1)  // 全在l左侧(区间外)， 或全为一 则直接return-1   否则向下递归
  return -1; //无
  if(l==r)   
     return  l;//返回该位置
  int mid=(l+r)/2;
    pushdown(rt,mid-l+1,r-mid);//
  int t= query0(L,l,mid,rt<<1); //左半区间答案
  if(~t)return t; // 不是-1直接
  return query0(L,mid+1,r,rt<<1|1); //右半区间答案
}

int query1(int L,int l,int r,int rt){ //找l右边第一个1   l为查找位置
  if(r<L||!segtree[rt].val)  // 全在l左侧(区间外)， 或全为0 则直接return-1   否则向下递归
  return -1; //无
  if(l==r)   
     return  l;//返回该位置
  int mid=(l+r)/2;
  pushdown(rt,mid-l+1,r-mid);//
  int t= query1(L,l,mid,rt<<1); //左半区间答案
  if(~t)return t; // 不是-1直接
  return query1(L,mid+1,r,rt<<1|1); //右半区间答案
}

int querymaxpos(int l,int r,int rt){  // 所有区间找最高位1位置 （答案）   
    if(l==r)return l;
    int mid=(l+r)/2;
    pushdown(rt,mid-l+1,r-mid);//
    if(segtree[rt<<1|1].val)return querymaxpos(mid+1,r,rt<<1|1); //右半区间
    return querymaxpos(l,mid,rt<<1);
}



void solve(){
    memset(bits,0,sizeof bits);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bits[a[i]]++;
    }
for(int i=1;i<N;i++){// 模拟二进制进位操作   当心越界
    bits[i+1]+=(bits[i]>>1);
    bits[i]%=2;
}
build(1,N,1);

while(q--){
    int x,y;//
    cin>>x>>y;
    //先 第x位-1
    int pos1=query1(a[x],1,N,1); //
    updateRange(pos1,pos1,1,N,-1,1);  // pos1位 1变0
    if(pos1!=a[x]){ //
        updateRange(a[x],pos1-1,1,N,1,1);  //中间
    }
    a[x]=y;
    //在第y位+1
    int pos0=query0(a[x],1,N,1);
    updateRange(pos0,pos0,1,N,1,1);
    if(pos0!=a[x]){
        updateRange(a[x],pos0-1,1,N,-1,1);
    }
    cout<<querymaxpos(1,N,1)<<endl;
}


}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}



