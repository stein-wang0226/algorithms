#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int f[maxn][maxn];
int a[maxn],sum[maxn];//前缀和
int n,m;
//前i本书分给第j个人，记录前缀和，初始化f[i][1]数组。
void print(int l,int r) {
	int s=0;
	for(int i=r; i>=l; i--) {//****输出
		if(s+a[i]>f[m][n]) {//从后往前 不大于的最长值
			print(l,i);//在前
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

	scanf("%d%d",&n,&m);//书   人
	if(n==0) return 0;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum[i]=a[i]+sum[i-1];//计算前缀和
		f[1][i]=sum[i];//初始化
	}
	for(int i=2; i<=m; i++)
		for(int j=i; j<=n; j++) //前i个人拿j本 -> f[i] [j]
			for(int k=i; k<=j; k++)//k为最后一个人 拿的第一本 位置
				f[i][j]=min(f[i][j],max(f[i-1][k-1],sum[j]-sum[k-1]));//固定i，j  变化k找到最小值
	print(1,n);
	return 0;
}
