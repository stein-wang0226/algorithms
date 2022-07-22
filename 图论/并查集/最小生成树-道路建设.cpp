#include <bits/stdc++.h>
using namespace std;
int pre[105], n;
int dis[105][105];//
void init(int n) {  
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
  }
}

int find_r(int x) {      
  while (pre[x] != x) {  
   pre[x]=pre[pre[x]];//路径压缩
    x = pre[x];          
  }
  return x;
}
void merge(int x, int y) {
  int root_x = find_r(x);
  int root_y = find_r(y);
  if (root_x != root_y) {  
    pre[root_x] = root_y;  
  }
}
struct edge {
  int x, y;
  int dis;
  bool operator<(const edge &b) const { return dis < b.dis; }
} Edge[10010];

int main() {
    memset(Edge, 0, sizeof Edge);
    while(cin>>n){
    init(n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> dis[i][j];
      }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){//生成边
      for(int j=i+1;j<=n;j++){
        Edge[++cnt].dis=dis[i][j];
        Edge[cnt].x=i;
        Edge[cnt].y=j;
      }
    } 
     sort(Edge + 1, Edge + cnt + 1);
    int have_cnt=0,a,b;//已修建
    cin>>have_cnt;
    for(int i=1;i<=have_cnt;i++){
          cin>>a>>b;
          merge(a,b);
    }
    int minlen = 0;
    for (int i = 1; i <= cnt; i++) {//生成最小生成树
      if (find_r(Edge[i].x) != find_r(Edge[i].y)) {
        merge(Edge[i].x, Edge[i].y);
        minlen +=  Edge[i].dis;
      }
    }
    
  cout<<minlen<<endl;
  }
  return 0;
}