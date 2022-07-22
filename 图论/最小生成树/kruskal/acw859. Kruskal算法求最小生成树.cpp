#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//Kruskal    并查集  + 边排序
const int N=1e3+5;
const int M=2e3+5;
int n,m;
int pre[N];
int find(int x){
  if(x!=pre[x])pre[x]=find(pre[x]);
  return pre[x];
}
struct Edge{
  int u,v,w;
  bool operator <(const Edge &b)const{
    return w<b.w;
  } 
}edge[M];
using namespace std;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
for(int i=1;i<=n;i++)pre[i]=i;//init
for(int i=1;i<=m;i++){
  int a,b,w;
  cin>>a>>b>>w;
  edge[i]={a,b,w};
}
sort(edge+1,edge+m+1);
int ans=0;
for(int i=1;i<=m;i++){
  int u=find(edge[i].u);int v=find(edge[i].v);
  if(u!=v){
    pre[v]=u;//合并
    ans+=edge[i].w;
  }
}
int cnt=0;//计集合数
for(int i=1;i<=n;i++){
  if(find(i)==i)cnt++;
}
if(cnt==1){
  cout<<ans<<endl;
}
else cout<<"orz"<<endl;

    return 0;
}
