#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n,m, a[N];
int in[N],out[N];
vector<int>g[N];
int dp[N]; // 以i为起点的最长链长度
//找最长链
//只有出度入度大于0 才
void dfs(int u){
    if(dp[u])return ; //记忆化
    dp[u]=1; //起点
    if(out[u]<=1)return ;
    for(auto v:g[u]){
        dfs(v);
        if(in[v]>1)dp[u]=max(dp[u],dp[v]+1); //只有入度大于1才转移
    }
}

void solve(){
    
cin>>n>>m;
int u,v;
for(int i=1;i<=m;i++){
    cin>>u>>v;
    g[u].push_back(v);
    in[v]++,out[u]++;
}
for(int i=1;i<=n;i++){
    dfs(i);
}
int ans=0;
for(int i=1;i<=n;i++){
    ans=max(ans,dp[i]);
}
cout<<ans<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


      solve();
  
  return 0;
}
