#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
// 题意：
// 1棵树，10000个节点，机器人路过每条边都有一个代价，现在在树上给出一个起始位置，在该位置放一些机器人，
// 希望机器人访问所有的节点且花费最小的代价，问最小代价是多少。
// 思路：
// 最多10个机器人，可以用树上背包来做。dp[i][j]表示在i节点，此时我有j个机器人可以用，最少需要多少代价访问
// 完所有以i节点为根节点的所有子节点。注意这里我们从起始位置出发，对于每个节点，不考虑父亲节点的情况，只
// 考虑以其为根节点的情况。这样对于dp[i][j]，我们对i节点的所有儿子跑背包，往下分配机器人，分配x个就会造成
// x*当前边费用的代价，特别的，这里j为0时表示我们不会为该节点分配机器人，即用1个机器人跑完所有子节点后返回
// i节点   // 特判  注意来回要两次
//。然后dfs对树上的点依次背包即可。
const int N = 2e4 + 5;

int T, n;
int s, k;  // 起点  机器人数
int head[N], tot;
int dp[N][12];
struct Edge {
  int from, to, w, next;
} edge[N * 2];
void add(int u, int v, int w) {
  edge[++tot].from = u;
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot;
}


void dfs(int u,int fa){

    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        int w=edge[i].w;
        dfs(v,u);
        // 回溯时dp
        for(int j=k;j>=0;j--){ //相当于背包体积
         dp[u][j]+=dp[v][0]+2*w;  //初始化为一个机器人走完整个子树  (每条路走两遍)下面循环不会执行
            for(int q=1;q<=j;q++) //更新背包（个数 从小到大）  （用小子树更新大子树）
                dp[u][j]=min(dp[u][j],dp[u][j-q]+dp[v][q]+q*w);
        }
    }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (cin >> n >> s >> k) {
    int u, v, w;
    memset(head,-1,sizeof head);
    memset(dp,0,sizeof dp);
    tot=0;
    for (int i = 1; i < n; i++) {
      cin >> u >> v >> w;
      add(u, v, w);
      add(v, u, w);
    }
    dfs(s,-1);
    cout<<dp[s][k]<<endl;
  }
  return 0;
}
