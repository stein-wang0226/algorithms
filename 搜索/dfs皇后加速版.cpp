
#include <bits/stdc++.h>

using namespace std;
const int N=15;
int vis[N][N],n;
int L[2*N]={0},R[2*N]={0},C[N]={0};//�Խ��ߡ�����������б��

int is_valid(int x,int y) {
	if(C[y]==1)return 0;
	if (R[x+y]==1)return 0;//�ҶԽ���x+yΪ��ֵ 
	if (L[y-x+n-1]==1)return 0;//��Խ��� x-yΪ��ֵ 
	return 1;
}
void print() { //output
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(vis[i][j]==1) {
				cout<<j+1<<" ";
			}
		}
	}
	cout<<"\n";
}

int cnt=0;
int num=3;//����ǰ3��
void dfs(int row0) { //һ��һ����

	if(row0==n) { //��������
		if(num) {
			num--;	   //����ý�
			print();
		}
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
			vis[row0][i]=0;//����(�ҵ�һ���Ժ�)
			R[i+row0]=0;
			L[i-row0+n-1]=0;
			C[i]=0;
		}
	}
}


int main() {
	memset(vis,0,sizeof vis);
	cin>>n;
	dfs(0);
	cout<<cnt;
	return 0;
}
