#include <bits/stdc++.h>
#define LOCAL
using namespace std;
// l,r 是大（总）区间 ，L，R是操作/查询区间
const int N =1e5+7;//元素总个数
int a[N];//原数组 可不用
struct Seg{
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
	
	//单点更新，假设 a[t]+=c   类似二进制，每层只需更新一个  从上到下
	void updateNode(int t,int c,int l,int r,int rt){//l,r 表示当前节点区间，rt表示当前根节点编号
	  if(l==r){
	    segtree[rt].val+=c;//    叶子节点  直接修改
	    return;
	  }
	  int mid=(l+r)/2;
	  if(t<=mid)  updateNode(t,c,l,mid,rt<<1);  //更新左子树
	  else    updateNode(t,c,mid+1,r,rt<<1|1);
	  pushup(rt);                          //回溯向上更新，相加
	}
	
	//区间查询(区间a[L....R]的和)   [L,R]为操作区间,[l,r]为当前区间，rt为节点编号
	int query(int L,int R,int l,int r,int rt){
	  if(L<=l&&r<=R)   
	    return  segtree[rt].val;//当前区间被包含 则直接返回(整个被加)
	  // 并且不再向下递归
	  if(L>r||R<l)    //当前区间全部不重和，则返回0，而且其子区间也不会包含
	  return 0;
	//否则部分包含  向下递归
	  int mid=(l+r)/2;
	  return  query(L,R,l,mid,rt<<1)+query(L,R,mid+1,r,rt<<1|1);
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
	int queryRange(int L,int R,int l,int r,int rt){
	  if(L<=l&&r<=R)   
	    return  segtree[rt].val;
	
	  if(L>r||R<l)    
	  return 0;
	
	  int mid=(l+r)/2;
	  pushdown(rt,mid-l+1,r-mid);//唯一不同,也是精华所在 ，查询到，必要时下推
	  return  queryRange(L,R,l,mid,rt<<1)+queryRange(L,R,mid+1,r,rt<<1|1);
	}
}seg;
