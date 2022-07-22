#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//tarjan 模板（缩点）
//原理 :dfs树包含若干个scc，通过找到起始节点(不唯一)将其分开
//一次dfs并入栈,当找到某个scc起始节点即找到整个scc出栈即可；
//起始节点u求法： u的所有子节点v 的最早祖先都不能先于u   low(u)<=dfn(n)(=成立)->low(u)==dfn(u)
//缩点：直接通过原点的scc 编号id建新图
const int N=1e5+5;
vector <int>G[N],G1[N];
int dfn[N],low[N];//dfs入栈时间 , 子节点最早祖先 
int id[N],dfs_clock;//scc编号   , 时间戳
int scc_cnt,n,m;
stack<int>S;

void dfs(int u){
    dfn[u]=low[u]=++dfs_clock;
    S.push(u);//入栈
    for(int i=0;i<G[u].size();i++){//dfs遍历
    int v=G[u][i];
    if(!dfn[v]){//未访问
        dfs(v);
        low[u]=min(low[u],low[v]);  
    }
    else if(!id[v]){//已经通过其他点访问但未生成scc
        low[u]=min(low[u],dfn[v]);//用反向边更新low     
    }
    }

    if(low[u]==dfn[u]){//满足起始节点条件
        scc_cnt++;
        for(;;){//将之后入栈的子节点出栈
        int x=S.top();S.pop();
        id[x]=scc_cnt;//编号
        if(x==u)break;//到u为止(最早)
        }
    }
}

void build(){//缩点后新图
  for(int i=1;i<=n;i++){//遍历
    for(int j=0;j<G[i].size();j++){
      int v=G[i][j];
      if(id[i]!=id[v]){//不为同一个scc
        G1[id[i]].push_back(id[v]);
      }
    }
  }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
  dfs_clock=scc_cnt=0;
  memset(id,0,sizeof id);
  memset(dfn,0,sizeof dfn);
  for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
    return 0;
}
