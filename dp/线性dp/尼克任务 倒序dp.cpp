//����dp   ������� ���뵽��f[i]:ǰi���ӣ���ǰiʱ�̵�������ʱ���Ǻ����һ��ѡ������ĳ���ʱ���ʱ���й�ϵ�ģ���һ�µ�����,����f[i]��ʾi~n��������ʱ��
#include<bits/stdc++.h>
#include<utility>
using namespace std;
const int maxn=1e4+5;
int n,k;

pair<int ,int >a[maxn];//��ʼ�� ����ʱ��
int dp[maxn];//f[i]��ʾi~n ��������ʱ��
int num[maxn];//num[i]��ʾ��i�����м�������ʼ
int main() {
	cin>>n>>k;
	memset(dp,0,sizeof dp);//initial;
	for(int i=1; i<=k; i++) {
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	for(int i=1; i<=k; i++) { //ͳ��num
		num[a[i].first]++;
	}
	sort(a+1,a+k+1);//����ʼʱ������
	
	int cnt=k;//��  �ѵ��ڼ�������
	for(int i=n; i>=1; i--) { //����
		if (num[i]==0)dp[i]=dp[i+1]+1;//��ʱ��������ʼ ,δȷ������Ĭ��ǰ��������
		else {
			for(int j=1; j<=num[i]; j++) {
				dp[i]=max(dp[i],dp[i+a[cnt].second]);//******�ص� �����������ÿ������ ���ҵ���Ӧ����ʱ���ʱ�̵�dpֵΪ���������������ȷ����ȡmax
				cnt--;//
			}
		}
	}


			cout<<dp[1];

	return 0;
}
