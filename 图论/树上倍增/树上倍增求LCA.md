# 树上倍增求LCA

[TOC]

## 思路：

从x,y向上爬直到相遇（深度大的先爬）

## 倍增实现：

### 	 	预处理

​	预处理各个节点的深度和2^i级祖先dep[i]

​	fa[x] [k]  x的2^k 级祖先

### 求lca

先让x,y跳到同一深度，那么lca就是他们的n级祖先

从大到小尝试（2的幂次）,如果x,y 不相同就向上跳2^k 层

祖先相同则说明跳过头了，k- -;

结果x,y肯定是他们lca的儿子

最终返回fa[x] [0]  ---->lca

------

## 代码实现

```C++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
int n,m,s;
struct Edge{
	int from,to,next,val;
}edge[N*2];
int head[N],tot;
int dep[N],fa[N][30]; //深度  和 2^k级祖先
int lg[N]; //预处理log2
void add(int u,int v){
	edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}

void init() {  //预处理log2  
  lg[0] = -1;  //这样 lg[1] 为0
  for (int i = 1; i <= N; i++) {
    lg[i] = lg[i / 2] + 1;  
      // 也可以这样lg[i] = ((i & (i - 1)) == 0) ? lg[i- 1] + 1 : lg[i - 1]   
  }
}
//dfs获得每个结点的 dep 和fa
void dfs(int u,int father){  //O(nlogn) 预处理
    fa[u][0]=father;// 一级祖先即父节点
    dep[u]=dep[father]+1; //更新深度
    for(int i=1;i<=lg[dep[u]];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];  //理解：2^i =2^(i-1)+2^(i-1)
    }
    for(int i=head [u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==father)continue;
        dfs(v,u);   //向下搜
    }
}

//求lca
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y); //默认x更深
   for(int i=lg[dep[x]];i>=0;i--)
    {
        if(dep[fa[x][i]]>=dep[y])
        {
            x=fa[x][i];
        }
    }
// 这样能使 x,y达到相同深度
    if(x==y)
        return x;
    for(int k=lg[dep[x]];k>=0;k--){
        if(fa[x][k]!=fa[y][k])  //不相等 说明在lca下方
            x=fa[x][k],y=fa[y][k];  //  namo向上爬  
    }//结果x,y肯定是他们lca的儿子
    return fa[x][0];  //返回父节点 即lca
} 
signed main(){
	cin>>n>>m>>s;
    int u,v;
    memset(dep,0,sizeof dep);
    memset(head,-1,sizeof head);
    tot=0;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }

   	init();
       
    dfs(s,0);
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
		cout<<LCA(x,y)<<endl;
    }
}
    
    
    

    
```

