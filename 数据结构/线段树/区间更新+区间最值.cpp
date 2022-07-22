#include <bits/stdc++.h>
using namespace std;
//不用 *区间长度 
const int N =1e5+7;//
struct segtreenode{
  int val;
  int lazy ;//懒惰标记  
}segtree[N<<2];
void pushup(int rt){
  segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val);
}
//ln,rn 分别为左右子区间大小
void pushdown(int rt,int ln,int rn){
  if(segtree[rt].lazy){//有懒惰标记
    segtree[rt<<1].lazy+=segtree[rt].lazy;//更新左右子区间的值和懒惰标记
    segtree[rt<<1|1].lazy+=segtree[rt].lazy;
    segtree[rt<<1].val+=segtree[rt].lazy;// 最大值不用*
    segtree[rt<<1|1].val+=segtree[rt].lazy;
    segtree[rt].lazy=0;//** 清除标记
  }
}
//区间更新
void updateRange(int L,int R,int l,int r,int c,int rt){
    if(L<=l&&r<=R){//  
        segtree[rt].val+=c;     //更新区间max 
        segtree[rt].lazy+=c;     
        return ;
    }
    int mid=(l+r)/2;
    pushdown(rt,mid-l+1,r-mid);// 
    if(L<=mid) updateRange(L,R,l,mid,c,rt<<1);
    if(R>mid) updateRange(L,R,mid+1,r,c,rt<<1|1);  
    pushup(rt);
}
//区间查询
int Rangemax(int L,int R,int l,int r,int rt){
  if(L<=l&&r<=R)   
    return  segtree[rt].val;
  if(L>r||R<l)    
  return 0;
  int mid=(l+r)/2;
  pushdown(rt,mid-l+1,r-mid);
  return  max(Rangemax(L,R,l,mid,rt<<1),Rangemax(L,R,mid+1,r,rt<<1|1));
}
int main(){
int m,n;
cin>>n>>m;
n--; //线段 l,r-1
// 
 ifstream fin;
    fin.open("1.txt");
    if(!fin.is_open()){
        cout<<"打开失败"<<endl;
        return 0;
    }
for(int i=1;i<=m;i++){//订单
    int l,r;  //订单起始点
    // cin>>l>>r; //
    fin>>l>>r;
    updateRange(l,r-1,1,n,1,1);
}
    fin.close();
int ans=Rangemax(1,n,1,n-1,1);
cout<<ans<<endl;
}