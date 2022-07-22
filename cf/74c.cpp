
//n^4暴力+剪枝
//先预处理二维前缀和，之后在枚举最后一列之前的代价如果比现在所得的最小代价还要大的话就break
//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int inf=2e18+100;
const int maxn=2e5+100;
char a[510][510];
int sum[510][510];
int get(int i,int j,int i2,int j2)
{
	return sum[i2][j2]-sum[i2][j-1]-sum[i-1][j2]+sum[i-1][j-1];
}
signed main()
{
	IOS
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>(a[i]+1);
			for(int j=1;j<=m;j++)
			{
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]-'0';
			}
		}
		int ans=16;
		for(int i=1;i<=n-4;i++)
		{
			for(int j=1;j<=m-3;j++)
			{
				for(int i2=i+4;i2<=n;i2++)
				{
					int now=0;
					for(int j2=j+3;j2<=m;j2++)
					{
						int tp=0;
						tp=get(i+1,j+1,i2-1,j2-1);
						tp+=(i2-i-1)-get(i+1,j,i2-1,j);//-get(i+1,j2,i2-1,j2);
						tp+=2*(j2-j-1)-get(i,j+1,i,j2-1)-get(i2,j+1,i2,j2-1);
						ans=min(ans,tp+(i2-i-1)-get(i+1,j2,i2-1,j2));
						now=max(now,tp);
						if(now>ans)break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}


