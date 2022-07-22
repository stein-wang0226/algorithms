#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//求出每个强连通分量，然后求出入度为0的强联通分量，取出他们中打电话花费最少的，加起来就是结果。
const int MAX = 1050;
int n,m, cnt1,cnt2, head1[MAX],head2[MAX];  //存每个点的第一条边(最后加上的)
int Min[MAX],sum;
int vis1[MAX], vis2[MAX], f[MAX];
int cost[MAX];
vector<int> S;
set<int>st;//储存缩点后点编号
struct Edge {
  int from,to, dis, next;//from便于缩点
} edge1[MAX * 2],edge2[MAX*2];
void add_edge1(int from, int to, int w) {
  edge1[++cnt1].to = to;
  edge1[cnt1].from=from;
  edge1[cnt1].dis = w;
  edge1[cnt1].next = head1[from];  //该点的上一条边
  head1[from] = cnt1;
}
void add_edge2(int from, int to, int w) {
  edge2[++cnt2].to = to;
  edge2[cnt2].from=from;
  edge2[cnt2].dis = w;
  edge2[cnt2].next = head2[from];  //该点的上一条边
  head2[from] = cnt2;
}
void dfs1(int u) {
  vis1[u] = 1;
  for (int i = head1[u]; ~i; i = edge1[i].next)  //链式前向星遍历u相连边
    if (!vis1[edge1[i].to]) dfs1(edge1[i].to);
    S.push_back(u);
}

void dfs2(int u, int y) {  // y为该scc第一个点,即每次dfs的第一个点
  vis2[u] = 1;
  f[u] = y;  //**缩点**   将整个scc缩为y点
  Min[y]=min(Min[y],cost[u]);//记录每个scc最小值
  for (int i = head2[u]; ~i; i = edge2[i].next) {
    if (!vis2[edge2[i].to]) dfs2(edge2[i].to, y);
  }
}
void build(){// 实现缩点 -->DAG图   因为f[x]表示x所属 scc,所以对原图的边
cnt1=0;//
memset(head1,-1,sizeof head1);               // x->y   ，在新图中添加 f[x]->f[y]的边
for(int i=1;i<=m;i++)if(f[edge1[i].from]!=f[edge1[i].to]) 
add_edge1(f[edge1[i].from],f[edge1[i].to],f[edge1[i].dis]); //注意特判 f[x]==f[y]的情况,过滤掉自环
}
int main() {
  std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
while(cin>>n>>m){
    memset(head1, -1, sizeof(head1));
   memset(head2, -1, sizeof(head2));
  memset(vis1, 0, sizeof vis1);
  memset(vis2, 0, sizeof vis2);
   memset(Min, 0x3f, sizeof Min);
   memset(cost,0,sizeof cost);
  memset(f, -1, sizeof f);
  st.clear();
  S.clear();
  cnt1 = cnt2=0;
  for(int i=1;i<=n;i++)cin>>cost[i];
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    add_edge1(u,v,0);
    add_edge2(v,u,0);
  }
  for (int i = 1; i <= n; i++)
    if (!vis1[i]) dfs1(i);
    for (int i = n - 1; i >= 0; i--){
    if (!vis2[S[i]]) {dfs2(S[i], S[i]);st.insert(S[i]);  }//*缩点的序号f[] 即dfs的第一个点
  }
  build();//缩点
  sum=0;
  int count=0;
  memset(vis1,0,sizeof vis1);
for(int i=1;i<=cnt1;i++){
  vis1[edge1[i].to]=1;//入度不为1
}
for(auto i:st){
  if(vis1[i]==0){
    count++;
    sum+=Min[i];
  }
}
  cout<<count<<" "<<sum<<endl;
}
return 0;
}
