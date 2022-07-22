//任意合并-》贪心
//相邻合并  区间dp
//环形合并   将序列首尾相连为两边，转化为相邻
#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int dp1[maxn][maxn],dp2[maxn][maxn];
int sum [maxn];
int a[maxn];
int n;

int main() {
	cin>>n;
    memset(dp1,0,sizeof(dp1));
    memset(sum,0,sizeof(sum));
	memset(dp2,0,sizeof(dp2));
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		dp1[i][i]=dp2[i][i]=0;//初始 长度为1 为0 
		sum[i]=sum[i-1]+a[i];//前缀和
	}
	int cnt=1;
	for(int j=n+1; j<=2*n; j++) {
		sum[j]=sum[j-1]+a[cnt++];
	}
	
	for(int len=2;len<=n;len++){//枚举区间长度 从二开始 
		for(int i=1;i<=2*n;i++){//枚举 起始位置 
			int j=i+len-1;//结尾位置 
			dp1[i][j]=-1;//求max 
			dp2[i][j]=1e8;//求min 
			if(j>2*n)break;//越界结束
			for(int k=i;k<j;k++){//间断点位置 
				dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);//枚举间断点求最值   
				dp2[i][j]=min (dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
			} 
			
		} 
	}
	int MAX=-1;int MIN=1e8;
	for(int i=0;i<n;i++){//枚举环状序列的起点，长度为n,若为直接 dp[1][n] 
        MAX=max(dp1[i+1][i+n],MAX);
         MIN=min(dp2[i+1][i+n],MIN);
	}
	cout<<MIN<<"\n"<<MAX;
	return 0;
}
