#include <bits/stdc++.h>
//#define LOCAL
using namespace std;
//染色法判定二分图
const int N=1e5+5;
const int M=2e5+5;
int head[N],tot,color[N];//  color 01 两种颜色
struct Edge{
  int from,to,ne;
}edge[M];
void add(int u,int v){
  edge[++tot].from=u;
  edge[tot].to=v;
  edge[tot].ne=head[u];
  head[u]=tot;
}
bool dfs(int u,int c){
  color[u]=c;   //染色
  for(int i=head[u];~i;i=edge[i].ne){
    int v=edge[i].to;
    if(color[v]==color[u])return 0;  //相邻颜色相同
    if(color[v]==-1&&!dfs(v,1-c))return 0; //未染色   但dfs染色之后会找到矛盾
  }
  return 1;
}

int m,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
 tot=0;memset(head,-1,sizeof head);
 memset(color,-1,sizeof color);//未染色
 cin>>n>>m;
 for(int i=1;i<=m;i++){
   int a,b;
   cin>>a>>b;
   add(a,b);
   add(b,a);//无向图
 }
 int flag=1;
 for(int i=1;i<=n;i++){
   if(color[i]==-1){//未染色
     if(!dfs(i,0)){flag=0;break;}//染成0    判断存在矛盾  存在就跳出
   }
 }
 if (flag) puts("Yes");
    else puts("No");
    return 0;
}
