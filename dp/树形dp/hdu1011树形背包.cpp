#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 110
struct Edge
{
    int next,to;
}edge[N*N/2];
int head[N<<1],tot;

int n,m;
int p[N];
int vis[N];
int bugs[N];
int dp[N][N];

void dfs(int u)
{
    vis[u]=1;
    int i,j,k,v;
    int r=bugs[u]%20?bugs[u]/20+1:bugs[u]/20;
    for(i=r;i<=m;i++)
    {
        dp[u][i]=p[u];
    }
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(!vis[v])
        {
            dfs(v);
            for(j=m;j>=r;j--)
            {
                for(k=1;k<=j-r;k++)
                {
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+ dp[v][k]);
                }
            }
        }
    }
}
void add(int x,int y)
{
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
}
int main()
{
    while(scanf("%d%d",&n,&m), (n+1)||(m+1))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&bugs[i],&p[i]);
        }
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        if(m==0) cout<<0<<endl;             //0个士兵，一无所获
        else
        {
            dfs(1);
            cout<<dp[1][m]<<endl;
        }
    }
    return 0;
}