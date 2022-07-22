#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//没有上司的舞会
int t,n,a[6005],in[6005];//in入度  a开心值
vector<int>G[6005];
int dp[6005][2];//dp[i][1/0]第i个点去或不去  子树的快乐总值
//dp[u][0]+=max(dp[v][0],dp[v][1])之和   u去 v可去可不去 取最大情况
//dp[u][1]+=dp[v][0] 之和    u去子节点一定不去
void dfs(int u){//dp    DAG图无需标记
  for(int j=0;j<G[u].size();j++){
      int v=G[u][j];
     dfs(v);//递归到叶子结点
     }
  //*****回溯时dp***核心   （从叶子开始）
for(int j=0;j<G[u].size();j++){
  int v=G[u][j];
  dp[u][0]+=max(dp[v][0],dp[v][1]);
  dp[u][1]+=dp[v][0];
}
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n,n){
memset(a,0,sizeof a);
memset(dp,0,sizeof dp);
memset(in,0,sizeof in);
for(int i=1;i<=n;i++){
  cin>>a[i];
  dp[i][1]=a[i];//初值直接装
   G[i].clear();
}
 int u,v;
for(int i=1;i<n;i++){//肯定n-1
  cin>>u>>v;
  G[v].push_back(u);//v->u 注意
  in[u]++;
}
cin>>u>>v;//两个0
int root=0;
for(int i=1;i<=n;i++){
  if(in[i]==0){//入度为0  根结点
    dfs(i);
    root=i;
    break;
  }
}
int ans=max(dp[root][1],dp[root][0]);
cout<<ans<<endl;
}
    return 0;
}
