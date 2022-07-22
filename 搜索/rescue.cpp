#include <bits/stdc++.h>
#define LOCAL
using namespace std;  //
int t, vis[25][25], m, n;
char  Map[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node {
  int x, y, step;  
}start,End;
int bfs(node start) {
  queue<node>q;//优化
  q.push(start);
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if(u.x==End.x&&u.y==End.y)return u.step;
    node cur;
    for (int i = 0; i < 4; i++) {
     cur.x = u.x + dx[i];
      cur.y = u.y + dy[i];
      cur.step=u.step+1;
      if(Map[cur.x][cur.y]=='*'){
          cur.x+= dx[i];
      cur.y  += dy[i];
        cur.step++;}
      if (!vis[cur.x][cur.y] && cur.x > 0 && cur.x <= m && cur.y > 0 &&
          cur.y <= n&&Map[cur.x][cur.y]=='.') {
          vis[cur.x][cur.y] = 1; 
          q.push(cur);
      }
    }
  }
  return -1;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> m >> n) {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> Map[i][j];
      }
    }
    cin>>start.x>>start.y>>End.x>>End.y;
    vis[start.x][start.y]=1;
       int ans= bfs(start);
       cout<<ans<<endl;
    }

  
  return 0;
}
