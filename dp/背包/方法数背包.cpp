#include<bits/stdc++.h>//��һ ����������dp  ��ֵ->���  ����������� 
using namespace std;
const int maxn=1e4+5;
int N,M,sum=0; 
int w[maxn],f[105][1005] ;
int main(){
	cin>>N>>M;
	memset(f,0,sizeof f); 
	for(int i=1;i<=N;i++){//��1��ʼ 
 		scanf("%d",&w[i]);
	}
	for(int i=1;i<=N;i++){//dp ��ǰi��ѡ�ķ����� �����Ż�Ϊһά 
		for(int j=1;j<=M;j++){
		if(j==w[i])f[i][j]=f[i-1][j]+1;//����ΪǮ������ ����+1
		else if(j>w[i])f[i][j] =f[i-1][j]+f[i-1][j-w[i]];//���۴��� w[i]��  ������Ϊf[i-1][j] +  f[i-1][j-w[i]] -->ǰi������w[i]��ϳ�j�ķ���  
		else if (j<w[i])     f[i][j]=f[i-1][j]; //���۴����ܽ�  ����
		} 
	}
	cout<<f[N][M]; 
	return 0;
} 
