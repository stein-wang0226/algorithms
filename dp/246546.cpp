#include<bits/stdc++.h>
using namespace std;
const int N=505;
int m,k;
int c[N],dp[N][N],index[2*N];//dp[i][j] ǰi���� ǰj���� ����С ʱ��
int main() {
	cin>>m>>k;
	memset(dp,0,sizeof dp);//����װ�����ʼ��Ϊ0
	for(int i=1; i<=m; i++) {
		scanf("%d ",&c[i]);
	}
	index[1]=1;
	int pos=1,tot=1;
	for(int i=1; i<=k; i++) { //
		for(int j=1; j<=m; j++) { //��
			dp[i][j]=min(dp[i][j-1]+c[i],max(dp[i-1][j-1],c[j]));//*****ungerstandǰ�����󣺼ӵ���һ��
		
			}
		}
	

	return 0;
}
