#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 4e2 + 5;

int T, n, m,a[N];
int dp[N][N]; //dp[i][j]对已i为根的子树  从中选j个子节点(背包容量)的最大价值
//由题将0视为根结点
int  val[N];
struct Edge{
    int from,to,next;
}edge[2*N];
int head[N],tot;
void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u){  //有向秃
    //dp[u][1]=val[u];   //也可以在这里初始化
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
        //回溯 dp
        for(int j=m+1;j>=2;j--){//倒序枚举数量（容量）
            for(int k=1;k<j;k++) //子结点所代表子树
                dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k]);//第k个选于不选
        }

    }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

while(cin>>n>>m,m+n){
    int a,w;
    memset(head,-1,sizeof head);
    tot=0;
    memset(dp,0,sizeof dp);
    memset(val,0,sizeof val);
    for(int i=1;i<=n;i++){
            cin>>a>>w;
            add(a,i); //有向边 代表先a后i
            val[i]=w;  //价值
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=val[i]; //1~n 初始化为val[i]  至少要选根节点
    }

    dfs(0); //假设0为根节点

    cout<<dp[0][m+1]<<endl;
}
  return 0;
}
