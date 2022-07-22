#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 50;
int T, n,m,q, a[N];
int maxx[N];
struct segtreenode{
  int val;
  int lazy ; 
}segtree[N<<2];
void pushup(int rt){
  segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val);
}
void pushdown(int rt,int ln,int rn){
  if(segtree[rt].lazy){//鏈夋噿鎯版爣璁?
    segtree[rt<<1].lazy+=segtree[rt].lazy;//鏇存柊宸﹀彸瀛愬尯闂寸殑鍊煎拰鎳掓儼鏍囪
    segtree[rt<<1|1].lazy+=segtree[rt].lazy;
    segtree[rt<<1].val+=segtree[rt].lazy;// 鏈€澶у€间笉鐢?
    segtree[rt<<1|1].val+=segtree[rt].lazy;
    segtree[rt].lazy=0;//** 娓呴櫎鏍囪
  }
}
void updateNode(int t,int c,int l,int r,int rt){//l,r 琛ㄧず褰撳墠鑺傜偣鍖洪棿锛宺t琛ㄧず褰撳墠鏍硅妭鐐圭紪鍙?
  if(l==r){
    segtree[rt].val+=c;//    鍙跺瓙鑺傜偣  鐩存帴淇敼
    return;
  }
  int mid=(l+r)/2;
  if(t<=mid)  updateNode(t,c,l,mid,rt<<1);  //鏇存柊宸﹀瓙鏍?
  else    updateNode(t,c,mid+1,r,rt<<1|1);
  pushup(rt);                          
}
int Rangemax(int L,int R,int l,int r,int rt){
  if(L<=l&&r<=R)   
    return  segtree[rt].val;
  if(L>r||R<l)    
  return 0;
  int mid=(l+r)/2;
  pushdown(rt,mid-l+1,r-mid);
  return  max(Rangemax(L,R,l,mid,rt<<1),Rangemax(L,R,mid+1,r,rt<<1|1));
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        updateNode(i,a[i],1,m,1);
    }
    cin>>q;
    while(q--){
        int x1,x2,y1,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        if(y1>y2)swap(x1,x2),swap(y1,y2);
        int flag=1;
        int dx=abs(x1-x2);
        int dy=abs(y1-y2);
        if(dx%k||dy%k){flag=0;cout<<"NO"<<endl;continue;}
        int maxx=0;
        if((abs(y2-y1))>1)maxx=Rangemax(y1+1,y2-1,1,m,1);
        else {

            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;    
            continue;
            }
        if(maxx>=x1&&maxx>=x2){
            int dh=maxx-x1+1;
            if(dh%k==0){
                if(maxx>=n){flag=0;cout<<"NO"<<endl;continue;}
                else {cout<<"YES"<<endl;continue;}
            }
            else{
             int  tt=dh/k+1;
             if(x1+tt*k>n){flag=0;cout<<"NO"<<endl;continue;}
             if(maxx>=n){flag=0;cout<<"NO"<<endl;continue;}
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }



}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  T=1;
  while (T--) {
      solve();
  }
  return 0;
}
