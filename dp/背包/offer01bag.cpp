#include<cstring>
//#define min(a,b) a<b?a:b
#include <iostream>
#include<cstdio>
//01  ����һ��offer��������:1-0�ݵ���С���� 
using namespace std;
const int maxn=1e4+5;
int n,v,c[105];
double w[105],dp[maxn];
int main() {
	while(~scanf("%d %d",&v,&n)&&(v||n)){

	for(int i=1;i<=n;i++){
		scanf("%d %lf",&c[i],&w[i]);
		w[i]=1-w[i]; 		//ʧ�ܸ��� 
	}
   for(int i=0;i<=10;i++)dp[i]=1.0;//��ʼ��Ϊ1.0*** 
   
		for(int i=1; i<=n; i++) {
			for(int j=v; j>=c[i]; j--) { //01
				dp[j]=min(dp[j],dp[j-c[i]]*(w[i]));//*���� 
			}
		}
		double ans=1.0-dp[v];//�ɹ����� 
printf("%.1lf%%",ans*100.0); 
		}
	return 0;
}
