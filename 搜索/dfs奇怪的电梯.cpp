#include <bits/stdc++.h>//dfs 
using namespace std;
int n,a,b,k[201],minstep,step=0;
int vis[201];//标记是否已经到过
void dfs(int x,int y);
int main() {
	cin>>n>>a>>b;
	minstep=n+1;//保证被改变
	for(int i=1; i<=n; i++)cin>>k[i]; //input
	memset(vis,0,sizeof(vis));
	dfs(a,0);
	if(vis[b])printf("%d",minstep);
	else cout<<"-1";
	return 0;
}
void dfs(int a,int step) {
	if(a<1||a>n)return; //unvalid
	if(a==b||step>=n||vis[a]||step>minstep) { //跳出条件 若有解深度为n时必已有解,已经到过则重复，剪枝 
		if(step<minstep&&a==b) {//更优解则更新并记录 
			minstep=step;
			vis[b]=1;//标记代表有解 
		}
		return;
	}
	vis[a]=1;
	step++;
	dfs(a+k[a],step);
	dfs(a-k[a],step);
	vis[a]=0;//回溯 
}













