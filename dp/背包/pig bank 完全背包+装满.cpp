#include<bits/stdc++.h>
#define inf  0x3f3f3f3f
//pig bank  :��ȫ����+װ�� 
using namespace std;
const int maxn=10005;
int t,a,b,v,n,w[505],c[505],dp[maxn]; 
int main(){
	cin>>t;
	while(t--){
		scanf("%d %d %d",&a,&b,&n);//nΪӲ������ 
		v=b-a;//���� 
			dp[0]=0;//   ���Ϊ0 �Ϸ�             
	for(int i=1;i<=v;i++)
		dp[i]=inf;      //װ�� ��С--����ʼ��������  ��  ��� ������-�� 0xc0 
	for(int i=1;i<=n;i++){
		scanf("%d %d",&w[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=c[i];j<=v;j++){//��ȫ����  ������һά 
			dp[j]=min(dp[j],dp[j-c[i]]+w[i]);
		}
	}
if(dp[v]<50000000)printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
else   printf("This is impossible.\n");
}
	return 0;
}
