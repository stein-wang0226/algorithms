
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int minn=0xc0c0c0c0;
bool vis[105];
int n,m,t,d,st,ed,sum,res,power[105],a[105][105],dp[10005],dis[105];
void dij()
{
	for(int i=0;i<105;i++)
	{
		dis[i]=inf;
		vis[i]=false;	
	}//初始化
	dis[0]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,Min=inf;
		
        for(int j=0;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<Min)
			{
				u=j;
				Min=dis[j];
			}
		}//选取最近的点 
		if(u==-1)
			return ;
		vis[u]=true;
		for(int k=0;k<=n;k++)
		{
			if(!vis[k]&&a[u][k]!=inf&&dis[u]+a[u][k]<dis[k])
			{
				dis[k]=dis[u]+a[u][k];
			}
		}//松弛，更新最短路
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=0;i<105;i++)
			for(int j=0;j<105;j++)
				a[i][j]=inf;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>st>>ed>>d;
			a[st][ed]=a[ed][st]=min(d,a[st][ed]);
		}//注意同样的路径也许存在多组数据，需要选取距离最近的计入 
		dij();
		sum=res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>power[i];
			res+=power[i];
			if(dis[i]!=inf)//判断筛除无法到达的 
				sum+=dis[i];
		}//记录电力总和，同时统计可到达的发电站距离和作为背包容量 
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=sum;j>=dis[i];j--)
			{
				dp[j]=max(dp[j],dp[j-dis[i]]+power[i]);
			}
		}//一定距离内可控制的最大电力
		int flag=1;
		for(int i=1;i<=sum;i++)
		{
			if(dp[i]>=res/2+1)//可控制电力大于一半符合要求 
			{
				flag=0;
				cout<<i<<endl;//输出所需最小路程即耗油量 
				break;
			}
		}
		if(flag)
			cout<<"impossible"<<endl;
	}
	return 0;
}
