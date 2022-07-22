#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t,p,n,m,V;
int G[305][305],link[305],vis[305];
int dfs(int u){//对左点搜索
  for(int v=1;v<=n;v++){//每个右点
    if(G[u][v]&&!vis[v]){
      vis[v]=1;
      if(link[v]==-1||dfs(link[v])){
        link[v]=u;//u,v匹配
        return 1;
      }
    }
  }
return 0;
}
int hungary(){
int res=0;
memset(link,-1,sizeof link);//初始化
for(int u=1;u<=p;u++){
  memset(vis,0,sizeof vis);//每连一次标记清0
  if(dfs(u))res++;
}
return res;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
  memset(G,0,sizeof G);
  cin>>p>>n;
  for(int j=1;j<=p;j++){
   cin>>m; 
  for(int i=1;i<=m;i++){
    cin>>V;
    G[j][V]=1;//左为课  右为学生
  }
  }
  int ans=hungary();
  if(ans==p)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
    return 0;
}
