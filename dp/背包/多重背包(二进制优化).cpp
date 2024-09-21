#include<bits/stdc++.h>

//pig bank  :完全背包+装满
using namespace std;
const int maxn=102;
int t,v,n,w[maxn],c[maxn],m[maxn],dp[maxn];//  价值  体积  数量  
int main() {

	cin>>t;
	while(t--) {
		memset(dp,0,sizeof dp);
		scanf("%d %d ",&n,&v);//n为种数,v为金额
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&c[i],&w[i],&m[i]);
		}

//		for(int i=1; i<=n; i++) {
//			for(int j=v; j>=c[i]; j--) {
//				for(int k=0; k<=m[i]&&k*c[i]<=j; k++)//每样拿几个   ***从0 开始
//					dp[j]=max(dp[j],dp[j-k*c[i]]+k*w[i]);
//			}
//		}
		//二进制优化
		for(int i=1; i<=n; i++) {
			int num=min(m[i],v/c[i]);//最多能放个数，优化上界
			for(int k=1; num>0; k<<=1) { //将 m[i]依次分为k g个 （1，2，4，8 ....，余数）
				if(k>num)k=num;//取余
				num-=k;
				for(int j=v; j>=c[i]*k; j--) {//01 bag
					dp[j]=max(dp[j],dp[j-k*c[i]]+k*w[i]);
				}
			}
		}
		cout<<dp[v]<<"\n";
	}
	return 0;
}
