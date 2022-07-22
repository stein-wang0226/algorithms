#include<bits/stdc++.h>
//完全背包  vn优化 
using namespace std;
int t,m;//
const int maxn=1e5+5;

int c[maxn],w[maxn];
long long dp[10000005];//防爆栈，一维 
int main() {
	cin>>t>>m;
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&c[i],&w[i]);
	}
	memset(dp,0,sizeof dp);
	for(int i=1;i<=m;i++){
		for(int j=c[i];j<=t;j++){//一维 正序恰满足完全背包（小背包放过一种后后面可继续放） 
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	} 
	cout<<dp[t];

		return 0;
	}
