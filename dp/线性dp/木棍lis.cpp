//木棍，lis  最长连续递减为 单次最多数，最长递增为 **最少次数  每次取最长下降--》 不下降子序列最小个数等于最大上升子序列的长度
#include<bits/stdc++.h>
using namespace std;
int n,dp[5005];
struct couple {
	int first,second; 
	bool operator<(const couple&a)const{
	if(first!=a.first)return first>a.first;
	else return second>a.second;
	}
}p[5005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].first,&p[i].second);
		dp[i]=1;
	}
sort(p+1,p+n+1);//先按first排序再按second，这样只需考虑second  变为普通序列  保证每次取最长递减 ，对应 不下降子序列最小个数即最大上升子序列的长度


	int Max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(p[i].second>p[j].second)dp[i]=max(dp[i],dp[j]+1);
		} 
		Max=max(Max,dp[i]);
	}
	cout<<Max; 
	return 0;
}
