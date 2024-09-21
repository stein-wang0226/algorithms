#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e18;
int T,n,m,k,t;
int tim[N];
int vis[N];
int val[N]; // 存该点最小获取时间
vector<pair<int,int>>G[N];
int dfs(int x){
    if(vis[x])return val[x];//

    int ans = inf;
    for(auto i:G[x]){
      val[i.first]=dfs(i.first);
      val[i.second]=dfs(i.second);
      ans = min (ans, max(val[i.second],val[i.first])+max(tim[i.second],tim[i.first]));
    }
    vis[x]=1;
    return ans;
  }


  void solve(){
    cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++)cin>>tim[i];
      int id;
    for(int i=1;i<=m;i++){
      cin>>id;vis[id]=1;
        val[id]=0; // 已获取
      }
      int a,b,c;
      for(int i=1;i<=k;i++){
        cin>>a>>b>>c;
        G[c].emplace_back(a,b);
      }
      cout<<dfs(t);




    }
    signed main() {

      std::ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);

      solve();

      return 0;
    }
