//����ϲ�-��̰��
//���ںϲ�  ����dp
//���κϲ�   ��������β����Ϊ���ߣ�ת��Ϊ����
#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int dp1[maxn][maxn],dp2[maxn][maxn];
int sum [maxn];
int a[maxn];
int n;

int main() {
	cin>>n;
    memset(dp1,0,sizeof(dp1));
    memset(sum,0,sizeof(sum));
	memset(dp2,0,sizeof(dp2));
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		dp1[i][i]=dp2[i][i]=0;//��ʼ ����Ϊ1 Ϊ0 
		sum[i]=sum[i-1]+a[i];//ǰ׺��
	}
	int cnt=1;
	for(int j=n+1; j<=2*n; j++) {
		sum[j]=sum[j-1]+a[cnt++];
	}
	
	for(int len=2;len<=n;len++){//ö�����䳤�� �Ӷ���ʼ 
		for(int i=1;i<=2*n;i++){//ö�� ��ʼλ�� 
			int j=i+len-1;//��βλ�� 
			dp1[i][j]=-1;//��max 
			dp2[i][j]=1e8;//��min 
			if(j>2*n)break;//Խ�����
			for(int k=i;k<j;k++){//��ϵ�λ�� 
				dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);//ö�ټ�ϵ�����ֵ   
				dp2[i][j]=min (dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
			} 
			
		} 
	}
	int MAX=-1;int MIN=1e8;
	for(int i=0;i<n;i++){//ö�ٻ�״���е���㣬����Ϊn,��Ϊֱ�� dp[1][n] 
        MAX=max(dp1[i+1][i+n],MAX);
         MIN=min(dp2[i+1][i+n],MIN);
	}
	cout<<MIN<<"\n"<<MAX;
	return 0;
}
