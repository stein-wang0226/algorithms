//ľ����lis  ������ݼ�Ϊ ����������������Ϊ **���ٴ���  ÿ��ȡ��½�--�� ���½���������С��������������������еĳ���
#include<bits/stdc++.h>
using namespace std;
int n,dp[5005];
struct couple {
	int first,second; 
	bool operator<(const couple&a)const{
	if(first!=a.first)return first>a.first;
	else return second>a.second;
	}
}p[5005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].first,&p[i].second);
		dp[i]=1;
	}
sort(p+1,p+n+1);//�Ȱ�first�����ٰ�second������ֻ�迼��second  ��Ϊ��ͨ����  ��֤ÿ��ȡ��ݼ� ����Ӧ ���½���������С������������������еĳ���


	int Max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(p[i].second>p[j].second)dp[i]=max(dp[i],dp[j]+1);
		} 
		Max=max(Max,dp[i]);
	}
	cout<<Max; 
	return 0;
}
