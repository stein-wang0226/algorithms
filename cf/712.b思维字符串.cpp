#include <bits/stdc++.h>

using namespace std;
const int N=15;
int vis[N][N],n;
int L[2*N]={0},R[2*N]={0},C[N]={0};//�Խ��ߡ�����������б�ǣ��ӿ������ٶ�

int is_valid(int x,int y) {
	if(C[y]==1)return 0;
	if (R[x+y]==1)return 0;//�ҶԽ���x+yΪ��ֵ 0��2n-2
	if (L[y-x+n-1]==1)return 0;//��Խ��� x-yΪ��ֵ 
	return 1;
}
int cnt=0;
void dfs(int row0) { //һ��һ����
if(row0==n) { //��������
		cnt++;
		return;
	}
	for(int i=0; i<n; i++) { //����ÿ��i
		if (is_valid(row0,i)) {
			vis[row0][i]=1;//����
			R[i+row0]=1;//
			L[i-row0+n-1]=1;
			C[i]=1; 
			dfs(row0+1);//�ݹ����
			vis[row0][i]=0;//����(�ҵ�һ���Ժ�)****
			R[i+row0]=0;
			L[i-row0+n-1]=0;
			C[i]=0;
		}
	}
}


int main() {
int ans[11];
for( n=1;n<=10;n++){
	cnt=0;
	dfs(0);
	ans[n]=cnt;
}
int t; 
while(cin>>t,t){
	cout<<ans[t]<<endl;
}
	return 0;
}
