#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//缩点  点权为子节点个数；
//找出度为0的点  反向dfs统计路径上点权和最大值
const int MAX = 5010;
vector<int> G[MAX], G1[MAX];
int in[MAX];//入度
int dfn[MAX], low[MAX];     // dfs入栈时间 , 子节点最早祖先
int index[MAX], dfs_clock;  // scc编号   , 时间戳
int vis[MAX];
int scc_cnt, t,n, m;
stack<int> S;
int node_cnt[MAX];
int value;
int dfs2[MAX];
void dfs(int u) {
  dfn[u] = low[u] = ++dfs_clock;
  S.push(u);                               //入栈
  for (int i = 0; i < G[u].size(); i++) {  // dfs遍历
    int v = G[u][i];
    if (!dfn[v]) {  //未访问
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (!index[v]) {  //已经通过其他点访问但未生成scc
      low[u] = min(
          low[u],
          dfn[v]);  //用反向边更新low     此处dfn[u]==low[u](以访问) 可与上合并
    }
  }

  if (low[u] == dfn[u]) {  //满足起始节点条件
    scc_cnt++;
    for (;;) {  //将之后入栈的子节点出栈
      int x = S.top();
      S.pop();
      index[x] = scc_cnt;    //编号
      node_cnt[index[x]]++;  //缩点后节点数
      if (x == u) break;     //到u为止(最早)
    }
  }
}

void build() {              //缩点后建反图图
  for (int i = 0; i < n; i++) {  //遍历
    for (int j = 0; j < G[i].size(); j++) {
      int v = G[i][j];
      if (index[i] != index[v]) {  //不为同一个scc   v->index[i]
        G1[index[v]].push_back(index[i]);
		in[index[i]]++;//入度
      }
    }
  }
}

void Dfs2(int u){//只搜入度为0 
	vis[u]=1;
	value+=node_cnt[u];
	for(int j=0;j<G1[u].size();j++){
		if(!vis[G1[u][j]])
		Dfs2(G1[u][j]);
	}
}
int Case=0;
int main() {
  std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
   clock_t c1 = clock();
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    Case++;
    cout<<"Case "<<Case<<": ";
    cin>>n>>m;
    for(int i=0;i<=n;i++){G[i].clear();G1[i].clear();}//***
    for(int i=1;i<=m;i++){
      int u,v;
      cin>>u>>v;
      G[u].push_back(v);
    }
    dfs_clock = scc_cnt = 0;
    memset(index, 0, sizeof index);
    memset(dfn, 0, sizeof dfn);
    memset(node_cnt,0,sizeof node_cnt);
    for (int i = 0; i < n; i++)
      if (!dfn[i]) dfs(i);
      
memset(in,0,sizeof in);
   build();//缩点

  
memset(dfs2,0,sizeof dfs2);
  int maxx=-1;
  for(int i=1;i<=scc_cnt;i++){  
	  memset(vis,0,sizeof vis);
	  value=0;
    if(in[i]==0)Dfs2(i);
	dfs2[i]=value-1;
    maxx=max(maxx,value-1);
  } 
  cout<<maxx<<endl;

  set<int>st1;//新图 最大结点
  set<int>st2;//原图最大结点
  for(int i=1;i<=scc_cnt;i++){
    if(dfs2[i]==maxx)st1.insert(i);
  }
  for(int i=0;i<n;i++){
    if(st1.count(index[i]))st2.insert(i);
  }
int ans[MAX];
int len=0;
  for(auto i:st2){//存答案
	  	ans[++len]=i;
  }
  for(int i=1;i<=len;i++){
	  cout<<ans[i];
	  if(i!=len)cout<<" ";
  }

  cout<<endl;
    }
  return 0;
}
