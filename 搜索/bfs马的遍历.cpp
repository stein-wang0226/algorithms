#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
//最短路 bfs
using namespace std;
int  n,m, x,y;;
int num[405][405];//储存记录最小步数
const int dx[8]= {1,1,2,2,-1,-1,-2,-2};
const int dy[8]= {2,-2,1,-1,2,-2,1,-1};
struct node {
	int x;
	int y;
};
void bfs() {//x,y 为初始点
	queue<node>q;
	num[x][y]=0;//c初始点为0 
	q.push({x,y});//首元素入队列
	while(!q.empty()) { //不空
		node u=q.front();
		q.pop(); //扔掉首元素，并储存于u
		for(int i=0; i<8; i++) {
			int mx=u.x+dx[i];
			int my=u.y+dy[i];//下一步 ，更新坐标,mxmy记录当前坐标
			if(mx>0&&my>0&&mx<=n&&my<=m&&num[mx][my]==-1) { //panduan 界内，且未走过
				num[mx][my]=num[u.x][u.y]+1;//下一步步数
				q.push({mx,my});//该步进队列
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d",&n,&m,&x,&y);
	memset(num,-1,sizeof(num));//初始-1 
	bfs();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		printf("%-5d",num[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
