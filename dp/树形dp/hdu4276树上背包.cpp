/*
树形DP
先找出1到N的边，将这些边的时间修改为0.然后就是简单的树形DP了
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=110;

struct Node
{
    int next;
    int to;
    int val;
}edge[MAXN*2];
int tol;
int head[MAXN];

int dp[MAXN][550];//dp[i][j]表示从第i个点开始，回到i点，花费j时间得到的最大财富值

int value[MAXN];//每个点的财富值

int time1;//从1到N需要的时间
int n;

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void add(int a,int b,int val)
{
    edge[tol].to=b;
    edge[tol].next=head[a];
    edge[tol].val=val;
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].next=head[b];
    edge[tol].val=val;
    head[b]=tol++;
}

bool dfs1(int u,int pre)
{
    if(u==n)return true;//找到了
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        if(dfs1(v,u))
        {
            time1+=edge[i].val;
            edge[i].val=0;
            return true;
        }
    }
    return false;
}
int t;
void dfs2(int u,int pre)
{
    for(int i=0;i<=t;i++) dp[u][i]=value[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs2(v,u);
        int cost=edge[i].val*2;//要走两遍
        for(int i=t;i>=cost;i--)
           for(int j=0;j<=i-cost;j++)
             dp[u][i]=max(dp[u][i],dp[v][j]+dp[u][i-j-cost]);
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int u,v,w;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        for(int i=1;i<=n;i++)scanf("%d",&value[i]);
        time1=0;
        dfs1(1,-1);//找从1到N的最短时间
        if(t<time1)
        {
            printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
            continue;
        }
        t-=time1;
        dfs2(1,-1);
        printf("%d\n",dp[1][t]);
    }
    return 0;
}