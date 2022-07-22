#include <stdio.h>
#include<iostream>
#include <algorithm>
#include <cstring>
#include <queue>//状压搜索

using namespace std;

struct Node {
  int x, y;
  int bx, by;
  int num;
  bool friend operator<(const Node &a, const Node &b) {
    return a.num > b.num;
  }  //优先队列
} star;

int map[9][9];
bool vis[9][9][9][9];  //用人跟箱子的位置标记状态
int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
int n, m, ans;

//输入地图，找到人跟位置的点。

int BFS() {
  Node now, next;
  priority_queue<Node> Q;

  Q.push(star);

  vis[star.x][star.y][star.bx][star.by] = true;

  while (!Q.empty()) {
    now = Q.top();
    Q.pop();

    if (map[now.bx][now.by] == 3) return now.num;  //如果箱子到终点退出搜索

    for (int i = 0; i < 4; i++)  //四个方向循环
    {
      next.x = now.x + dir[i][0];//人向四周搜索移动***,若碰到箱子则向同方向推开
      next.y = now.y + dir[i][1];

      if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)  //越界 继续
        continue;

      if (map[next.x][next.y] == 1)  //墙 继续
        continue;

      next.bx = now.bx;
      next.by = now.by;
      next.num = now.num;  //注意题目要求统计的是箱子的移动个数

      if (next.x == now.bx && next.y == now.by)  //如果下个方向是箱子的位置,人才能推
      {//向同方向推开
       //***用同一个循环的 dir 代表人推的方向与箱子相对人方向相同****   
        int xx = next.x + dir[i][0];//箱子推到的位置
        int yy = next.y + dir[i][1];

        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;//这里就包括墙角的情况

        if (map[xx][yy] == 1) continue;

        next.bx = xx;
        next.by = yy;
        next.num++;
      }

      if (vis[next.x][next.y][next.bx][next.by])  //如果推完后的状态已经经历过就不推了
        continue;                            

      vis[next.x][next.y][next.bx][next.by] = true;
      Q.push(next);
    }
  }
  return -1;
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int T, ans;
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));  //最重要的初始话忘记了，wa了几次
    scanf("%d%d", &n, &m);

    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
      cin>>map[i][j];
        if (map[i][j] == 4) {
          star.x = i;
          star.y = j;
          map[i][j] = 0;
        }
        if (map[i][j] == 2) {
          star.bx = i;
          star.by = j;
          map[i][j] = 0;
        }
      }
    }

    star.num = 0;

   int ans = BFS();
    cout<<ans<<endl;
  }
  return 0;
}