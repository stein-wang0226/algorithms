#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,s,f[N][20],dep[N],mn[N];  //f[u][i]表示 u的2^1级祖先 
int head[N],to[N<<1],next[N<<1],en; //mn[i] log(i)向下取整 
int lca(int x,int y){
	if(dep[x]!=dep[y]){//先使x,y跳到同一深度 
		if(dep[x]<dep[y])  swap(x,y);
		int k=dep[x]-dep[y];
		for(int i=0;;i++){
		if(!k) break;
		if(k&1) x=f[x][i];
		k>>=1;
		}	 
	}
	if(x==y) return x; //特判x,y中一个位另一个的祖先的情况 
	for(int i=mn[dep[x]];i>=0;i--)//使x,y跳到lca的儿子 
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0]; //返回任意一个的父亲节点 
}                                                               
void dfs(int u,int fa){
	f[u][0]=fa;//记录2^0级祖先 
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
