#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e3 + 5;
//最少用几个哨兵能覆盖整棵树  类似没有上司的舞会
// 树形dp   dp[i][0]表示i为根节点的子树放哨兵的子树 最小值 
//dp[ i][1]表示放
const int inf=0x3f3f3f3f;

int T, n, dp[N][2];
int tot,head[N];
struct Edge{
  int from,to,next;
}edge[N*2];
void add(int u,int v){
  edge[++tot].from=u;
  edge[tot].to=v;
  edge[tot].next=head[u];
  head[u]=tot;
}

void dfs(int u,int fa){
  dp[u][1]=1;
  dp[u][0]=0;
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].to;
    if(v==fa)continue;
    dfs(v,u);
    dp[u][0]+=dp[v][1];
    dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}
signed main() {

  while(cin>>n)
    {
      tot=0;
      memset(head,-1,sizeof head);
        for(int i=0;i<n;i++)  //下标从0
        {
            dp[i][1]=dp[i][0]=inf;
        }
        for(int i=0;i<n;i++)
        {
            int u,v,m;
            scanf("%d:(%d)",&u,&m);
            for(int j=0;j<m;j++)
            {
                cin>>v;
                add(u,v);
                add(v,u);
            }
        
        dfs(0,-1);
        
        }
        cout<<min(dp[0][0],dp[0][1])<<endl;
    }
  return 0;
}
