#include<bits/stdc++.h>
using namespace std;
int T,n,m,u,v,cas,a[1010],temp[1010];
int vis[110],dis[110],fa[110],Map[110][110];
void SPFA()
{
    queue<int> q;
    q.push(1);vis[1]=1;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        vis[u]=0;
        for(int i=2;i<=n+1;i++)
        {
            if(Map[u][i] && dis[i]<dis[u]+a[i])
            {
                dis[i]=dis[u]+a[i];
                fa[i]=u;
                if(!vis[i]) q.push(i),vis[i]=1;
            }   
        }   
    } 
}
int main()
{
    cin.tie(0);cas=0;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        memset(Map,0,sizeof Map);
        memset(a,0,sizeof a);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            Map[u][v]=1;
        }
        SPFA(); 
        cout<<"CASE "<<++cas<<"#"<<endl;
        int flag=fa[n+1],cnt=0;
        temp[0]=1;
        while(flag)
        {
            temp[++cnt]=flag;
            flag=fa[flag];
        }
        cout<<"points : "<<dis[n+1]<<endl;
        cout<<"circuit : ";
        for(int i=cnt;i>=0;i--) i==0? cout<<temp[i]<<endl : cout<<temp[i]<<"->"; 
        if(T) cout<<endl;   
    }
    return 0;
}
