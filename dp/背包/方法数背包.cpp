#include<bits/stdc++.h>//法一 方法数背包dp  价值->体积  结果：方法数 
using namespace std;
const int maxn=1e4+5;
int N,M,sum=0; 
int w[maxn],f[105][1005] ;
int main(){
	cin>>N>>M;
	memset(f,0,sizeof f); 
	for(int i=1;i<=N;i++){//从1开始 
 		scanf("%d",&w[i]);
	}
	for(int i=1;i<=N;i++){//dp 在前i中选的方案数 可以优化为一维 
		for(int j=1;j<=M;j++){
		if(j==w[i])f[i][j]=f[i-1][j]+1;//单价为钱总数的 方案+1
		else if(j>w[i])f[i][j] =f[i-1][j]+f[i-1][j-w[i]];//单价大于 w[i]的  方案数为f[i-1][j] +  f[i-1][j-w[i]] -->前i中能与w[i]组合成j的方案  
		else if (j<w[i])     f[i][j]=f[i-1][j]; //单价大于总金  不变
		} 
	}
	cout<<f[N][M]; 
	return 0;
} 
