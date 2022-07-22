#include <bits/stdc++.h>
using namespace std;
int a[25][15],n,k,dp[25][15];
int main() {
	while(~scanf("%d %d",&n,&k)) {
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++) { //input
			for(int j=1; j<=k; j++) {
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=n-1; i>=1; i--) {
			int Min=600000;
			for(int j=1; j<=k; j++) {
			int mi ;
				for(int m=1; m<=k; m++) {
					int ret=abs(a[i][j]-a[i+1][m]);
					if(ret<Min) {
						Min=ret;
						mi=m;
					}
				}
				dp[i][j]=Min+dp[i+1][mi];
			}
		}
		int ans=600*20;
		for(int i=1; i<=k; i++) {
			ans=min(ans,dp[1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
