#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<math.h>
#include<string>
//双连通分量+树形dp
using namespace std;
const int maxn=15000;
int n,head[maxn],tol,head1[maxn],tot,low[maxn],dfn[maxn],Stack[maxn],weight[maxn],indexx,scc,top,belong[maxn],dp[maxn],vis[maxn],weight1[maxn];
struct node
{
        int next,to;
}edge[100*maxn],edge1[100*maxn];
void add(int u,int v)
{
        edge[tol].to=v;
        edge[tol].next=head[u];
        head[u]=tol++;
}
void add1(int u,int v)
{
        edge1[tot].to=v;
        edge1[tot].next=head1[u];
        head1[u]=tot++;
}
void tarjan(int u,int pre)//边双连通
{
        low[u]=dfn[u]=++indexx;
        Stack[top++]=u;
        int i,v,flag=1;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
               v=edge[i].to;
               if(v==pre&&flag)
               {
                       flag=0;
                       continue;
               }
               if(!dfn[v])
               {
                       tarjan(v,u);
                       if(low[u]>low[v])low[u]=low[v];
               }
               else if(low[u]>dfn[v])low[u]=dfn[v];
        }
        if(low[u]==dfn[u])//桥的一端
        {
                scc++;
                do
                {
                        v=Stack[--top];
                        belong[v]=scc;
                }while(u!=v);
        }
}
void dfs(int u)
{
       if(vis[u])return;
       vis[u]=1;
       dp[u]+=weight1[u];
       int v,i;
       for(i=head1[u];i!=-1;i=edge1[i].next)
       {
              int v=edge1[i].to;
              if(!vis[v])
              {
                     dfs(v);
                     dp[u]+=dp[v];
              }
       }
}

void solve()
{
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        indexx=scc=top=0;
        tarjan(0,0);
       // cout<<scc<<endl;
        if(scc==1)
        {
                puts("impossible");return;
        }
        memset(head1,-1,sizeof(head1));tot=0;
        for(int u=0;u<n;u++)
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
                int v=edge[i].to;
                if(belong[u]!=belong[v])add1(belong[u],belong[v]);
        }
       // cout<<tot<<endl;
        memset(dp,0,sizeof(dp));
        memset(weight1,0,sizeof(weight1));
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++)weight1[belong[i]]+=weight[i],ans+=weight[i];
        dfs(1);
        int sum=ans;
        for(int i=1;i<=scc;i++)
        {
             int t=sum-dp[i];
             int p=abs(t-dp[i]);
             if(p<ans)ans=p;
        }
        printf("%d\n",ans);
}
int main()
{
        int i,j,k,m;
        while(~scanf("%d%d",&n,&m))
        {
                memset(head,-1,sizeof(head));
                tol=0;
                for(i=0;i<n;i++)scanf("%d",&weight[i]);
                while(m--)
                {
                        scanf("%d%d",&i,&j);
                        add(i,j);
                        add(j,i);
                }
                //cout<<tol<<endl;
                solve();
        }
        return 0;
}