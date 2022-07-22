#include <bits/stdc++.h>
#define LOCAL
// define int long long
using namespace std;
int  link[5005], vis[5005];
vector<int> G[5005];
int n,m,e;
int dfs(int u) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      vis[v] = 1;  //
      if(link[v]==-1||dfs(link[v])){//若v未匹配则匹配上,返回true,或继续向后搜直到匹配上
          link[v]=u;// 匹配上
          return 1;
      }
    }
  }
  return 0;  //未匹配上
}

int hungary(){
int res=0;
memset(link,-1,sizeof link);
for(int u=1;u<=n;u++){//遍历左侧点
    memset(vis,0,sizeof vis);
    if(dfs(u))res++;// dfs  搜到则答案++
}
return res;
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>n>>m>>e;
for(int i=1;i<=e;i++){
    int l,r;
    cin>>l>>r;
    G[l].push_back(r+n);
}
int ans=hungary();
    cout<<ans<<endl;
  return 0;
}
