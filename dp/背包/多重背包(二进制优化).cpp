#include<bits/stdc++.h>

//pig bank  :��ȫ����+װ��
using namespace std;
const int maxn=102;
int t,v,n,w[maxn],c[maxn],m[maxn],dp[maxn];//  ��ֵ  ���  ����  
int main() {

	cin>>t;
	while(t--) {
		memset(dp,0,sizeof dp);
		scanf("%d %d ",&n,&v);//nΪ����,vΪ���
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&c[i],&w[i],&m[i]);
		}

//		for(int i=1; i<=n; i++) {
//			for(int j=v; j>=c[i]; j--) {
//				for(int k=0; k<=m[i]&&k*c[i]<=j; k++)//ÿ���ü���   ***��0 ��ʼ
//					dp[j]=max(dp[j],dp[j-k*c[i]]+k*w[i]);
//			}
//		}
		//�������Ż�
		for(int i=1; i<=n; i++) {
			int num=min(m[i],v/c[i]);//����ܷŸ������Ż��Ͻ�
			for(int k=1; num>0; k<<=1) { //�� m[i]���η�Ϊk g�� ��1��2��4��8 ....��������
				if(k>num)k=num;//ȡ��
				num-=k;
				for(int j=v; j>=c[i]*k; j--) {//01 bag
					dp[j]=max(dp[j],dp[j-k*c[i]]+k*w[i]);
				}
			}
		}
		cout<<dp[v]<<"\n";
	}
	return 0;
}
