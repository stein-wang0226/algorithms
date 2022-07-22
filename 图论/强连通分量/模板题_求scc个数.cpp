//原理:欲通过dfs求强连通分量,必须按拓扑序遍历,所以两次dfs,第一次先求得拓扑序,再求得scc
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//强连通分量 模板 
//1.vector
const int MAX=100005;
int m,n;
vector<int> G[10005],G2[10005];//原图，反图
vector<int>S;// 部分拓扑序
int vis[10005],index[10005];//每个点所属scc编号
int scc_cnt;//scc数
//若要求每个点强连通分量数,通过index数组遍历每个点计数即可
void dfs1(int u ){
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)dfs1(G[u][i]);//继续dfs
    S.push_back(u);//得部分拓扑序
}

void dfs2(int u){
  if(index[u])return ;//相当于标记，若不计数可另用vis2标记
  index[u]=scc_cnt;//计数
  for(int i=0;i<G2[u].size();i++)dfs2(G2[u][i]);
}

void find_scc(int n){
  scc_cnt=0;
  S.clear();
  memset(index,0,sizeof index);
  memset(vis,0,sizeof vis);
  for(int i=1;i<=n;i++)dfs1(i);
  for(int i=n-1;i>=0;i--){//逆拓扑序遍历反图
    if(!index[S[i]]){//相当于标记
      scc_cnt++;//scc数
      dfs2(S[i]);
    }
  }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m,m+n){
  for(int i=0;i<10005;i++){
    G[i].clear();
    G2[i].clear();
  }
for(int i=1;i<=m;i++){
  int u,v;
  cin>>u>>v;
 G[u].push_back(v);
 G2[v].push_back(u);
}
find_scc(n);
//cout<<scc_cnt<<endl; 
if(scc_cnt==1)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
    return 0;
}
