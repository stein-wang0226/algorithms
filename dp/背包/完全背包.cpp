#include<bits/stdc++.h>
//��ȫ����  vn�Ż� 
using namespace std;
int t,m;//
const int maxn=1e5+5;

int c[maxn],w[maxn];
long long dp[10000005];//����ջ��һά 
int main() {
	cin>>t>>m;
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&c[i],&w[i]);
	}
	memset(dp,0,sizeof dp);
	for(int i=1;i<=m;i++){
		for(int j=c[i];j<=t;j++){//һά ����ǡ������ȫ������С�����Ź�һ�ֺ����ɼ����ţ� 
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	} 
	cout<<dp[t];

		return 0;
	}
