#include<bits/stdc++.h>
#define ll long long//���ǰ��ĺ��ǷǸ������ۼӺ������һ���Ⱥ�����������
//���ǰ��ĺ��Ǹ���������Ҫ�ƶ���ʼλ�ã�Ѱ�Һ������ 
using namespace std;//˼·���ǰ��Ϊ����������ӣ������������ȴ���Ƚϣ�֪����wei 
const int N=2e5+5;
int dp[N],cur[N];//dpǰi������Ӷκ�
int a[N];
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) { //input
		scanf("%d",&a[i]);}
	dp[0]=a[0];
	cur[0]=max(0,a[0]);//���ǿ�ͷΪ- 
	for(int i=1; i<n; i++) {
		if(cur[i-1]+a[i]>0)cur[i]=cur[i-1]+a[i];//cur Ϊ��ǰĩβ������  
		else cur[i]=0;//cur Ϊ������� �����¼� 
		if(a[i]>0)	dp[i]=max(dp[i-1],cur[i]);// �Ƚϵ�ǰβ���Ƿ����  ,����dp 
		else dp[i]=max(dp[i-1],a[i]);//aiΪ���򲻿��ܸ���,������a[i]Ϊ-����� 
	}
	printf("%d",dp[n-1]);
	return 0;
}
