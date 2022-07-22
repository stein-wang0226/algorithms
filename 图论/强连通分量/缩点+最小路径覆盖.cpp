//原理:欲通过dfs求强连通分量,必须按拓扑序遍历,所以两次dfs,第一次先求得拓扑序,再求得scc
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n,m,t;
//缩点后  求最小路径覆盖****n-最大匹配
const int MAX=1e5+5;
vector<int> G[MAX],G2[MAX],G3[MAX];//原图，反图,新图
vector<int>S;// 
int vis[MAX],index[MAX];//每个点所属scc编号
int scc_cnt;//scc数
void dfs1(int u ){
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)dfs1(G[u][i]);//继续dfs
    S.push_back(u);//得部分拓扑序
}

void dfs2(int u){
  if(index[u])return ;//相当于标记，若不计数可另用vis2标记
  index[u]=scc_cnt;//计数
  for(int i=0;i<G2[u].size();i++){
    dfs2(G2[u][i]);}
}

void build(){//缩点后新图
  for(int i=1;i<=n;i++){//遍历
    for(int j=0;j<G[i].size();j++){
      int v=G[i][j];
      if(index[i]!=index[v]){//不为同一个scc
        G3[index[i]].push_back(index[v]);
      }
    }
  }
}
void find_scc(int n){
  scc_cnt=0;
  S.clear();
  memset(index,0,sizeof index);
  memset(vis,0,sizeof vis);
  for(int i=1;i<=n;i++)dfs1(i);
  for(int i=n-1;i>=0;i--){//逆拓扑序遍历反图
    if(!index[S[i]]){//相当于标记
      scc_cnt++;//scc数
      dfs2(S[i]);
    }
  }
}
int  link[MAX];  // G[u][v]   link存右点对象
int vis1[MAX];     //对每次匹配右点访问过与否，防止重复
int dfs(int u) {  //*****从左侧搜
  for (int j=0;j<G3[u].size();j++) {  //对每个右侧点遍历
    int v=G3[u][j];
    if (!vis1[v]) {     //已访问过则无需继续
      vis1[v] = 1;
      if (link[v] == -1 ||
          dfs(link[v])) {  //****
                           //若v未匹配则匹配上,返回true,或继续向后搜直到匹配上
        link[v] = u;  // u ,v相匹配,为之后服务
        return 1;     //匹配上返回true
      }
    }
  }
  return 0;//匹配不上返回false
}
int hungary() {
  int res = 0;                    //最大匹配数
  memset(link, -1, sizeof link);  //初始化link为-1,都未匹配,无对象
  for (int u = 1; u <= scc_cnt; u++) {  //遍历左侧点向右匹配
    memset(vis1, 0, sizeof vis1);   //每次 匹配初始化vis 0
    if (dfs(u)) res++;            // dfs搜索,如果搜到匹配数+1;
  }
  return res;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin>>n>>m;
  for(int i=0;i<=n;i++){//
    G[i].clear();
    G2[i].clear(); G3[i].clear();
  }
for(int i=1;i<=m;i++){
  int u,v;
  cin>>u>>v;
  G[u].push_back(v);
 G2[v].push_back(u);
}
find_scc(n);
build();
int ans=hungary();
cout<<scc_cnt-ans<<endl;//
}
    return 0;
}
