//完全+二维费用背包
#include <bits/stdc++.h>
using namespace std;
int need,v,n,s;
int w[105],c[105];
int dp[105][105];//dp[i][j]满足消耗i忍耐力，杀j只的最大经验值
int main() {
	while(~scanf("%d %d %d %d",&need,&v,&n,&s)) {
		for(int i=1; i<=n; i++) {
			scanf("%d %d",&w[i],&c[i]);
		}
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++) {
			for(int j=c[i]; j<=v; j++) { //正序：完全    +二维费用
				for(int k=1; k<=s; k++) {
					dp[j][k]=max(dp[j][k],dp[j-c[i]][k-1]+w[i]);
				}
			}
		}
		int Max,flag=0;
		for(int i=1; i<=v; i++) { //找最大忍耐
			for(int j=1; j<=s; j++) {
				if(dp[i][j]>=need) { //升级了
					Max=v-i;
					flag=1;
				}
			}
			if(flag)break;
		}
if(dp[v][s]>=need)cout<<Max<<"\n";
else cout<<"-1"<<"\n";

	}
	return 0;
}
