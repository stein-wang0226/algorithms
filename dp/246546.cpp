#include<bits/stdc++.h>
using namespace std;
const int N=505;
int m,k;
int c[N],dp[N][N],index[2*N];//dp[i][j] 前i个人 前j本书 的最小 时间
int main() {
	cin>>m>>k;
	memset(dp,0,sizeof dp);//不用装满则初始化为0
	for(int i=1; i<=m; i++) {
		scanf("%d ",&c[i]);
	}
	index[1]=1;
	int pos=1,tot=1;
	for(int i=1; i<=k; i++) { //
		for(int j=1; j<=m; j++) { //优
			dp[i][j]=min(dp[i][j-1]+c[i],max(dp[i-1][j-1],c[j]));//*****ungerstand前：，后：加到下一人
		
			}
		}
	

	return 0;
}
