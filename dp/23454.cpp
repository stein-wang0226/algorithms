#include<bits/stdc++.h>
#define ll long long//���ǰ��ĺ��ǷǸ������ۼӺ������һ���Ⱥ�����������
//���ǰ��ĺ��Ǹ���������Ҫ�ƶ���ʼλ�ã�Ѱ�Һ������
using namespace std;//˼·���ǰ��Ϊ����������ӣ������������ȴ���Ƚϣ�֪����Ϊ��
const int N=2e5+5;
int  dp[N],cur[N];//dpǰi������Ӷκ�
int  a[N];
int t,n,Case=0;
int main() {
	cin>>t;
	while(t--) {
		Case++;
		int pos1=0,pos2=0,maxpos1,maxpos2;
		cin>>n;
		for(int i=0; i<n; i++) { //input
			scanf("%d",&a[i]);
		}
		dp[0]=a[0];
		cur[0]=max(0,a[0]);//���ǿ�ͷΪ-
		if(a[0]<0&&a[1]>=0)pos1=1;
		for(int i=1; i<n; i++) {
			if(cur[i-1]+a[i]>=0) {//cur Ϊ��ǰĩβ������
				cur[i]=cur[i-1]+a[i];
				pos2=i;
			} else  { //cur Ϊ������� �����¼�
				cur[i]=0;
				pos1=i+1;
			}
			if(a[i]>0) {
				dp[i]=max(dp[i-1],cur[i]);		// �Ƚϵ�ǰβ���Ƿ����  ,����dp
				if(cur[i]>dp[i-1]) {//����λ��
					maxpos1=pos1;
					maxpos2=pos2;
				}
			} else {
				dp[i]=max(dp[i-1],a[i]);    //aiΪ���򲻿��ܸ���
				if(a[i]>dp[i-1])	maxpos1=maxpos2=i;

			}
		}
		printf("Case %d:\n",Case);
		printf("%d %d %d",dp[n-1],maxpos1+1,maxpos2+1);
		if(t>0)	cout<<"\n"<<"\n";
		else  cout<<"\n";
	}
	return 0;
}
