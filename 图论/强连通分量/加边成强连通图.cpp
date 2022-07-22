#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//最少加几条边是图全连通
//缩点为DAG图  使强连通只需连头尾   即找入度和出度为0的点   数目较大者为答案
//注意特判缩点后 仅一个点情况
int t,m,n;
const int MAX=1e5+5;
vector <int>G[MAX],G1[MAX];
int dfn[MAX],low[MAX];//dfs入栈时间 , 子节点最早祖先 
int in[MAX],out[MAX];//入度，出度
int index[MAX],dfs_clock;//scc编号   , 时间戳
int scc_cnt;
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
  else if(!index[v]){//已经通过其他点访问但未生成scc
    low[u]=min(low[u],dfn[v]);//用反向边更新low     此处dfn[u]==low[u](以访问) 可与上合并
  }
}

if(low[u]==dfn[u]){//满足起始节点条件
    scc_cnt++;
    for(;;){//将之后入栈的子节点出栈
      int x=S.top();S.pop();
      index[x]=scc_cnt;//编号
      if(x==u)break;//到u为止(最早)
    }
}
}

void build(){//缩点后新图
  for(int i=1;i<=n;i++){//遍历***** 注意是否从0
    for(int j=0;j<G[i].size();j++){
      int v=G[i][j];
      if(index[i]!=index[v]){//不为同一个scc
        G1[index[i]].push_back(index[v]);
      }
    }
  }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin>>n>>m;
for(int i=1;i<=n;i++){G1[i].clear();G[i].clear();}
for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
}
  dfs_clock=scc_cnt=0;
  memset(index,0,sizeof index);
  memset(dfn,0,sizeof dfn);
  for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);

    build();//
   memset(in,0,sizeof in);
  memset(out,0,sizeof out);
    for(int u=1;u<=scc_cnt;u++){//统计新图入度 出度
        for(int j=0;j<G1[u].size();j++){
            int v=G1[u][j];
            in[u]++;
            out[v]++;
        }
    }
    int cnt_in=0,cnt_out=0;
    for(int i=1;i<=scc_cnt;i++){
        if(in[i]==0)cnt_in++;
        if(out[i]==0)cnt_out++;
    }
    int ans;
     ans=max(cnt_in,cnt_out);
     if(scc_cnt==1)ans=0;//特判*****   就一个点时
    cout<<ans<<endl;
}
    return 0;
}
