#include<bits/stdc++.h>
#define ll long long//如果前面的和是非负数，累加后面的数一定比后面的数本身大
//如果前面的和是负数，即需要移动起始位置，寻找后面的数 
using namespace std;//思路如果前面为正则继续向后加，遇到负数则先储存比较，知道和wei 
const int N=2e5+5;
int dp[N],cur[N];//dp前i项最大子段和
int a[N];
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) { //input
		scanf("%d",&a[i]);}
	dp[0]=a[0];
	cur[0]=max(0,a[0]);//考虑开头为- 
	for(int i=1; i<n; i++) {
		if(cur[i-1]+a[i]>0)cur[i]=cur[i-1]+a[i];//cur 为当前末尾正序列  
		else cur[i]=0;//cur 为负则清空 ，重新加 
		if(a[i]>0)	dp[i]=max(dp[i-1],cur[i]);// 比较当前尾列是否更大  ,更新dp 
		else dp[i]=max(dp[i-1],a[i]);//ai为负则不可能更大,但考虑a[i]为-的情况 
	}
	printf("%d",dp[n-1]);
	return 0;
}
