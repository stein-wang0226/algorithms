#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
char s[maxn][maxn];//�����ͼ������ 
int n,m,ans=0;
int book[maxn][maxn];//������� 
int dx[]={1,-1,0,0};//�������� 
int dy[]={0,0,1,-1};
bool judge(int x,int y) {//�ж��Ƿ�Խ�� 
	if(x>=1&&x<=n&&y>=1&&y<=m)
		return true;
	return false;
}
bool find() {
	for(int i=1;i<=n;i++) {//��Ϊi+1��j+1����������ķ�Χ��i<n,j<m 
		for(int j=1;j<=m;j++) {
			int sum=0;
			if(!judge(i,j))//Խ���жϣ����Խ�磬ֱ�������˵㣬������һ���� 
				continue;
			if(s[i][j]=='#')
				sum++;
			if(s[i+1][j]=='#')
				sum++;
			if(s[i][j+1]=='#')
				sum++;
			if(s[i+1][j+1]=='#')
				sum++;
			if(sum==3)//��ʱ�޷����ɳ����� 
				return false;	
		}
	}
	return true;
}
void dfs(int x,int y) {
	book[x][y]=1;//���ʹ��ģ����Ϊ1 
	for(int k=0;k<4;k++) {//�ĸ��������� 
		int tx=x+dx[k];
		int ty=y+dy[k];
		if(s[tx][ty]=='#'&&book[tx][ty]==0&&judge(tx,ty))//����Ǵ���ͬʱ��δ���ʹ������Ҳ�Խ�� 
			dfs(tx,ty);//������һ��������� 
	}
}
int main() {
	memset(book,0,sizeof(book));//����������� 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf(" %c",&s[i][j]);//%ǰ��Ŀո�����ȷ����������� 
	if(!find()) {//�޷����ɴ�ֻ 
		printf("Bad placement.\n");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='#'&&book[i][j]==0) {//��ʼ���� 
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("There are %d ships.\n",ans);
	return 0;
}
