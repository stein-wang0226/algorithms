//1421搬寝室 ：每次从n个中搬一对，疲劳度为两者差的平方成正比，求搬k对疲劳度最小值
//思路：排序后01背包问题变式，转移方程:n为前n个的最小值 f(n,k)=min( f(n-1,k),f(n-2,k-1)+(an-an-1)^2 )（第n件拿与不拿）
#include <bits/stdc++.h>
#define ll  long long
#define INIF 2147483646
using namespace std;
int n,k;
ll a[2005];
ll dp[2005][1005];
int main() {
	while(~scanf("%d %d ",&n,&k)) { //input
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);//注意+1 

		for(int i=0; i<=n; i++) {//不符合的设为无线 ,方便取min 
			for(int j=1; j<=k; j++) {
				dp[i][j]=INIF;
			}
		}
		dp[0][0]=0; 
		for(int i=2; i<=n; i++) { //dp
			for(int j=1; 2*j<=i; j++) {
				int m=(a[i]-a[i-1])*(a[i]-a[i-1]);
				 dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+m);
			}
		}

	printf("%lld\n",dp[n][k]);

	}

	return 0;
}
