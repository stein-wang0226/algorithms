//线性dp   ：特殊第 先想到设f[i]:前i分钟，但前i时刻的最大空闲时间是和最后一次选择任务的持续时间和时刻有关系的，试一下倒着搜,即设f[i]表示i~n的最大空闲时间
#include<bits/stdc++.h>
#include<utility>
using namespace std;
const int maxn=1e4+5;
int n,k;

pair<int ,int >a[maxn];//开始和 持续时间
int dp[maxn];//f[i]表示i~n 的最大空闲时间
int num[maxn];//num[i]表示第i分钟有几个任务开始
int main() {
	cin>>n>>k;
	memset(dp,0,sizeof dp);//initial;
	for(int i=1; i<=k; i++) {
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	for(int i=1; i<=k; i++) { //统计num
		num[a[i].first]++;
	}
	sort(a+1,a+k+1);//按开始时间升序
	
	int cnt=k;//记  搜到第几个任务
	for(int i=n; i>=1; i--) { //倒序
		if (num[i]==0)dp[i]=dp[i+1]+1;//本时刻无任务开始 ,未确定所有默认前面任务不做
		else {
			for(int j=1; j<=num[i]; j++) {
				dp[i]=max(dp[i],dp[i+a[cnt].second]);//******重点 若有任务遍历每个任务 ，找到对应持续时间后时刻的dp值为结果（后面的情况已确定）取max
				cnt--;//
			}
		}
	}


			cout<<dp[1];

	return 0;
}
