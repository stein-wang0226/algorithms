#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int f[maxn][maxn];
int a[maxn],sum[maxn];//ǰ׺��
int n,m;
//ǰi����ָ���j���ˣ���¼ǰ׺�ͣ���ʼ��f[i][1]���顣
void print(int l,int r) {
	int s=0;
	for(int i=r; i>=l; i--) {//****���
		if(s+a[i]>f[m][n]) {//�Ӻ���ǰ �����ڵ��ֵ
			print(l,i);//��ǰ
			printf("%d %d\n",i+1,r);
			return ;
		}
		s+=a[i];
	}
	printf("%d %d\n",1,r);
}
int main() {
	memset(sum,0,sizeof(sum));
	memset(f,0x3f3f3f,sizeof(f));

	scanf("%d%d",&n,&m);//��   ��
	if(n==0) return 0;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum[i]=a[i]+sum[i-1];//����ǰ׺��
		f[1][i]=sum[i];//��ʼ��
	}
	for(int i=2; i<=m; i++)
		for(int j=i; j<=n; j++) //ǰi������j�� -> f[i] [j]
			for(int k=i; k<=j; k++)//kΪ���һ���� �õĵ�һ�� λ��
				f[i][j]=min(f[i][j],max(f[i-1][k-1],sum[j]-sum[k-1]));//�̶�i��j  �仯k�ҵ���Сֵ
	print(1,n);
	return 0;
}
