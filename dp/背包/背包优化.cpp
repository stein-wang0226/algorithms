#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int m,n; 
int c[N],w[N],dp[N] ;
int main(){
	while(cin>>m>>n){
	if(m==-1&&n==-1)return 0;
	memset(dp,0xc0 ,sizeof dp);//����װ�����ʼ��Ϊ0 
	dp[0]=0;//
	for(int i=0;i<n;i++){
 		scanf("%d %d",&w[i],&c[i]);
	}
	for(int i=0;i<n;i++){// ����Ϊÿ�ζ���f[i][]��f[i-1][] �Ż�Ϊһά 
		for(int j=m;j>=c[i];j--){//  һάҪ���� �Ż�,�ȸ��������ģ���ֹӰ�죬�ռ�С��c[i]���ü��� 
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);//i ���벻��  ,����ÿ�ֱ��� 
		} 
	}
	if(dp[m]>=0)
	cout<<dp[m]<<endl; 
	else cout<<"-1"<<endl;
	}
	return 0;
} 
