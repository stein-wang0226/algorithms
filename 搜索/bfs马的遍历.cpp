#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
//���· bfs
using namespace std;
int  n,m, x,y;;
int num[405][405];//�����¼��С����
const int dx[8]= {1,1,2,2,-1,-1,-2,-2};
const int dy[8]= {2,-2,1,-1,2,-2,1,-1};
struct node {
	int x;
	int y;
};
void bfs() {//x,y Ϊ��ʼ��
	queue<node>q;
	num[x][y]=0;//c��ʼ��Ϊ0 
	q.push({x,y});//��Ԫ�������
	while(!q.empty()) { //����
		node u=q.front();
		q.pop(); //�ӵ���Ԫ�أ���������u
		for(int i=0; i<8; i++) {
			int mx=u.x+dx[i];
			int my=u.y+dy[i];//��һ�� ����������,mxmy��¼��ǰ����
			if(mx>0&&my>0&&mx<=n&&my<=m&&num[mx][my]==-1) { //panduan ���ڣ���δ�߹�
				num[mx][my]=num[u.x][u.y]+1;//��һ������
				q.push({mx,my});//�ò�������
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d",&n,&m,&x,&y);
	memset(num,-1,sizeof(num));//��ʼ-1 
	bfs();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		printf("%-5d",num[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
