#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
char s[maxn][maxn];//保存地图的数组 
int n,m,ans=0;
int book[maxn][maxn];//标记数组 
int dx[]={1,-1,0,0};//方向数组 
int dy[]={0,0,1,-1};
bool judge(int x,int y) {//判断是否越界 
	if(x>=1&&x<=n&&y>=1&&y<=m)
		return true;
	return false;
}
bool find() {
	for(int i=1;i<=n;i++) {//因为i+1和j+1，所以这里的范围是i<n,j<m 
		for(int j=1;j<=m;j++) {
			int sum=0;
			if(!judge(i,j))//越界判断，如果越界，直接跳过此点，进入下一个点 
				continue;
			if(s[i][j]=='#')
				sum++;
			if(s[i+1][j]=='#')
				sum++;
			if(s[i][j+1]=='#')
				sum++;
			if(s[i+1][j+1]=='#')
				sum++;
			if(sum==3)//此时无法构成长方形 
				return false;	
		}
	}
	return true;
}
void dfs(int x,int y) {
	book[x][y]=1;//访问过的，标记为1 
	for(int k=0;k<4;k++) {//四个方向搜索 
		int tx=x+dx[k];
		int ty=y+dy[k];
		if(s[tx][ty]=='#'&&book[tx][ty]==0&&judge(tx,ty))//如果是船，同时还未访问过，并且不越界 
			dfs(tx,ty);//继续下一个点的搜索 
	}
}
int main() {
	memset(book,0,sizeof(book));//标记数组清零 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf(" %c",&s[i][j]);//%前面的空格用来确保输入的完整 
	if(!find()) {//无法构成船只 
		printf("Bad placement.\n");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='#'&&book[i][j]==0) {//开始搜索 
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("There are %d ships.\n",ans);
	return 0;
}
