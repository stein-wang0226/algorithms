#include <bits/stdc++.h>  //思路 ：转化为angel 到几个朋友最短距离
using namespace std;
int Map[55][55][55];
int vis[55][55][55];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int a, b, c, flag, _, t;
struct node {
  int x, y, z, step;
} start;
int bfs(node start) {
  queue<node> que;
  que.push(start);
  while (!que.empty()) {
    node u = que.front();
    que.pop();
    if (u.x == a && u.y == b && u.z == c) {
      flag = 1;
      return u.step;
    }
    for (int i = 0; i < 6; i++) {
      node cur;
      cur.x = u.x + dx[i];
      cur.y = u.y + dy[i];
      cur.z = u.z + dz[i];
      if (cur.x > 0 && cur.x <= a && cur.y > 0 && cur.y <= b && cur.z > 0 &&
          cur.z <= c && Map[cur.x][cur.y][cur.z] == 0 && (!vis[cur.x][cur.y][cur.z])) {
        cur.step = u.step + 1;
        que.push(cur);
        vis[cur.x][cur.y][cur.z] = 1;
      }
    }
  }
  return -1;//出不来也要返回-1
}
int main() {
// freopen("data.in", "r", stdin);
 // freopen("data.out", "w", stdout);
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d%d%d", &a, &b, &c, &t);
    memset(vis, 0, sizeof vis);
    flag = 0;
    for (int i = 1; i <= a; i++) {//input
      for (int j = 1; j <= b; j++) {
        for (int k = 1; k <= c; k++) {
          scanf("%d", &Map[i][j][k]);
        }
      }
    }
    node start;
    start.x=1;
    start.y=1;
    start.z=1;
    start.step=0;
    int ans = bfs(start);
    if(ans<=t)
    cout<<ans<<"\n";
    else cout<<"-1"<<"\n";
  }
  //system("pause");
  return 0;
}