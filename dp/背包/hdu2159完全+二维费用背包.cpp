//��ȫ+��ά���ñ���
#include <bits/stdc++.h>
using namespace std;
int need,v,n,s;
int w[105],c[105];
int dp[105][105];//dp[i][j]��������i��������ɱjֻ�������ֵ
int main() {
	while(~scanf("%d %d %d %d",&need,&v,&n,&s)) {
		for(int i=1; i<=n; i++) {
			scanf("%d %d",&w[i],&c[i]);
		}
		memset(dp,0,sizeof dp);
		for(int i=1; i<=n; i++) {
			for(int j=c[i]; j<=v; j++) { //������ȫ    +��ά����
				for(int k=1; k<=s; k++) {
					dp[j][k]=max(dp[j][k],dp[j-c[i]][k-1]+w[i]);
				}
			}
		}
		int Max,flag=0;
		for(int i=1; i<=v; i++) { //���������
			for(int j=1; j<=s; j++) {
				if(dp[i][j]>=need) { //������
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
