#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//区间修改+区间查询 求和  模板题  += -> =
const int MAX=1e5+10;
int t,n,m;
int a[MAX];
struct segtreenode{
	int val;
	int lazy;
}segtree[MAX<<2];

void pushup(int rt){
	segtree[rt].val=segtree[rt<<1].val+segtree[rt<<1|1].val;
}

void build(int l,int r,int rt){
	segtree[rt].lazy=0;
	if(l==r){
	segtree[rt].val=1;
	return ;
	}
int mid=(l+r)/2;
build(l,mid,rt*2);
build(mid+1,r,rt*2+1);
pushup(rt);
}

void pushdown(int rt,int ln,int rn){
	if(segtree[rt].lazy){
		segtree[rt<<1].lazy=segtree[rt].lazy;
		segtree[rt<<1|1].lazy=segtree[rt].lazy;
		segtree[rt<<1].val=segtree[rt].lazy*ln;
        segtree[rt<<1|1].val=segtree[rt].lazy*rn;
        segtree[rt].lazy=0;//** 清除标记
	}
}
void updateRange(int L,int R,int l,int r,int c,int rt){//参数顺序不要搞错
	if(L<=l&&r<=R){
		segtree[rt].val=c*(r-l+1);
		segtree[rt].lazy=c;//
	return ;
	}
int mid=(l+r)/2;
pushdown(rt,mid-l+1,r-mid);
if(L<=mid) updateRange(L,R,l,mid,c,rt<<1);
if(R>mid) updateRange(L,R,mid+1,r,c,rt<<1|1);
pushup(rt);
}
int queryRangesum(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R)
		return segtree[rt].val;
if(L>r||R<l)return 0;
int mid=(l+r)/2;
pushdown(rt,mid-1,r-mid);//
return queryRangesum(L,R,l,mid,rt<<1)+queryRangesum(L,R,mid+1,r,rt<<1|1);
}
int main(){
	std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
for(int i=1;i<=t;i++){
cin>>n;
build(1,n,1);
cin>>m;
for(int i=1;i<=m;i++){
	int x,y,z;
	cin>>x>>y>>z;
	updateRange(x,y,1,n,z,1);
}
int ans=queryRangesum(1,n,1,n,1);
printf("Case %d: The total value of the hook is %d.\n",i,ans);



}
    return 0;
}
