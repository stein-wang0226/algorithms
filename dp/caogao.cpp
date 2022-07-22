#include<bits/stdc++.h>
//思维    因为X必为 unexitable   so 若能唯一确定grid  则所有.都为exitable    所以只需判断有.的左和上都是X  则undetermined（若都exitable 必不存在这种情况）
using namespace std ;
const int N =1e6+8;
int sum[N];
int biao[N];
int main() {
	int n ,m ,tem= 0 ;
	scanf("%d%d",&n,&m);
	char ve[n+10][m+10];
	for(int i= 1; i<=n; i++)scanf("%s",ve[i]+1);//一次读一行 ,下标从1开始 
	int s;
	scanf("%d",&s);
	for(int j=1 ; j<=m; j++) {
		for(int i =1 ; i<=n; i++) {
			if(i==1||j==1)continue;
			if((ve[i-1][j]=='X')&&(ve[i][j-1]=='X')) {//unexitable 
				biao[j]=1;//某一列 可确定 
				break;
			}
		}
	}
	for(int i =1; i<=m; i++) {
		if(biao[i])sum[i]=sum[i-1]+1;//前缀和 
		else sum[i]=sum[i-1];
	}
	while(s--) {
		tem=0;
		int a,b;
		scanf("%d%d",&a,&b);
		if(sum[b]-sum[a])cout<<"no"<<endl;//前缀和判断a~b列是否全  determined 
		else cout<<"yes"<<endl;
	}
	return 0;
}







