#include<bits/stdc++.h>
#define inf  0x3f3f3f3f
//pig bank  :完全背包+装满 
using namespace std;
const int maxn=10005;
int t,a,b,v,n,w[505],c[505],dp[maxn]; 
int main(){
	cin>>t;
	while(t--){
		scanf("%d %d %d",&a,&b,&n);//n为硬币种数 
		v=b-a;//容量 
			dp[0]=0;//   体积为0 合法             
	for(int i=1;i<=v;i++)
		dp[i]=inf;      //装满 最小--》初始化正无穷  ；  最大 负无穷-》 0xc0 
	for(int i=1;i<=n;i++){
		scanf("%d %d",&w[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=c[i];j<=v;j++){//完全背包  ：正序一维 
			dp[j]=min(dp[j],dp[j-c[i]]+w[i]);
		}
	}
if(dp[v]<50000000)printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
else   printf("This is impossible.\n");
}
	return 0;
}
