#include <bits/stdc++.h>
using namespace std;
int pre[105], n;
void init(int n) {
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
  }
}

int find_r(int p)//寻找根节点 
 {
    while(p!=pre[p]){
      pre[p]=pre[pre[p]];
      p=pre[p];
    }
      return p;
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

  while (scanf("%d",&n)&&n) {
    memset(Edge, 0, sizeof Edge);
    init(n);
    int flag = 0, cnt =  n * (n - 1) / 2;
    for (int i = 1; i <=cnt; i++) {
      scanf("%d%d%d%d",&Edge[i].x,&Edge[i].y,& Edge[i].dis ,&flag);
      if (flag) merge(Edge[i].x, Edge[i].y);
    }
    sort(Edge + 1, Edge + cnt + 1);
    int mincost = 0;
    for (int i = 1; i <=  n * (n - 1) / 2; i++) {  //生成最小生成树
      if (find_r(Edge[i].x) != find_r(Edge[i].y)) {
        merge(Edge[i].x, Edge[i].y);
        mincost += Edge[i].dis;
      }
    }
  printf("%d\n",mincost);
  }
  return 0;
}