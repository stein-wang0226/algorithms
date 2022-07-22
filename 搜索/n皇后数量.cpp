#include <bits/stdc++.h>

using namespace std;
const int N=15;
int vis[N][N],n;
int L[2*N]={0},R[2*N]={0},C[N]={0};//对角线、列用数组进行标记，加快搜索速度

int is_valid(int x,int y) {
	if(C[y]==1)return 0;
	if (R[x+y]==1)return 0;//右对角线x+y为定值 0，2n-2
	if (L[y-x+n-1]==1)return 0;//左对角线 x-y为定值 
	return 1;
}
int cnt=0;
void dfs(int row0) { //一行一行填
if(row0==n) { //跳出条件
		cnt++;
		return;
	}
	for(int i=0; i<n; i++) { //遍历每列i
		if (is_valid(row0,i)) {
			vis[row0][i]=1;//填上
			R[i+row0]=1;//
			L[i-row0+n-1]=1;
			C[i]=1; 
			dfs(row0+1);//递归遍历
			vis[row0][i]=0;//回溯(找到一种以后)****
			R[i+row0]=0;
			L[i-row0+n-1]=0;
			C[i]=0;
		}
	}
}


int main() {
int ans[11];
for( n=1;n<=10;n++){//因为小于10 所以记录所有 
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