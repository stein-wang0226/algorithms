#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,s,f[N][20],dep[N],mn[N];  //f[u][i]��ʾ u��2^1������ 
int head[N],to[N<<1],next[N<<1],en; //mn[i] log(i)����ȡ�� 
int lca(int x,int y){
	if(dep[x]!=dep[y]){//��ʹx,y����ͬһ��� 
		if(dep[x]<dep[y])  swap(x,y);
		int k=dep[x]-dep[y];
		for(int i=0;;i++){
		if(!k) break;
		if(k&1) x=f[x][i];
		k>>=1;
		}	 
	}
	if(x==y) return x; //����x,y��һ��λ��һ�������ȵ���� 
	for(int i=mn[dep[x]];i>=0;i--)//ʹx,y����lca�Ķ��� 
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0]; //��������һ���ĸ��׽ڵ� 
}                                                               
void dfs(int u,int fa){
	f[u][0]=fa;//��¼2^0������ 
	for(int i=head[u];i;i=next[i]){
		if(to[i]!=fa){
			dep[to[i]] = dep[u]+1;
			dfs(to[i],u);
		}
	}
}

void init(){
	for(int i=2;i<=n;i++) mn[i]= (i&(i-1))==0?mn[i-1]+1:mn[i-1];
	dfs(s,0);
	for(int i=1;i<=mn[n];i++)
		for(int j=1;j<=n;j++)
		f[j][i] = f[f[j][i-1]][i-1];
}

void add(int x,int y){
	to[++en] = y,next[en] = head[x] , head[x] = en;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	int x,y,z;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
