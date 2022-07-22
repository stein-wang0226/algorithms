#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int m,n; 
int c[N],w[N],dp[N] ;
int main(){
	while(cin>>m>>n){
	if(m==-1&&n==-1)return 0;
	memset(dp,0xc0 ,sizeof dp);//不用装满则初始化为0 
	dp[0]=0;//
	for(int i=0;i<n;i++){
 		scanf("%d %d",&w[i],&c[i]);
	}
	for(int i=0;i<n;i++){// ，因为每次都是f[i][]与f[i-1][] 优化为一维 
		for(int j=m;j>=c[i];j--){//  一维要倒序 优化,先更新体积大的，防止影响，空间小于c[i]则不用继续 
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);//i 拿与不拿  ,更新每种背包 
		} 
	}
	if(dp[m]>=0)
	cout<<dp[m]<<endl; 
	else cout<<"-1"<<endl;
	}
	return 0;
} 
