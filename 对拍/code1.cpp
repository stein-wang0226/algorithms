#include <bits/stdc++.h>

using namespace std;
int t, n, m, vis[10][10];
char Map[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int wall = 0, si, sj, di, dj, flag;
void dfs(int i, int j, int step);
int main() {  //迷宫 第t秒恰逃出
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while ((cin >> n >> m >> t) && (n || m ||t)) {  // input
    memset(vis, 0, sizeof vis);
    wall = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> Map[i][j];
        if (Map[i][j] == 'X') wall++;  //用于剪枝
        if (Map[i][j] == 'S') {
          si = i;
          sj = j;
        }  //记录起点位置
        if (Map[i][j] == 'D') {
          di = i;
          dj = j;
        }  //记录出口位置
      }
    }
    if (m * n - wall - 1 < t || (abs(di - si) + abs(dj - sj)) > t) {  //剪枝1,2
      cout << "NO"
           << "\n";
      return 0;
    }
    if ((abs(di - si) + abs(dj - sj)) % 2 != t % 2) {  // 奇偶性剪枝***
      cout << "NO"
           << "\n";
      return 0;
    }
    flag = 0;
    vis[si][sj] = 1;  //起点已走过*****细节
    dfs(si, sj, 0);
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
void dfs(int i, int j, int step) {
  if (i <= 0 || i > n || j <= 0 || j > m) return;
  if (step == t && i == di && j == dj) {
    flag = 1;  // t秒恰找到出口
    return;
  }
  if (flag) return;  //已找到则中止所有递归*****
  for (int h = 0; h < 4; h++) {
    if (Map[i + dx[h]][j + dy[h]] != 'X' &&
        !(vis[i + dx[h]][j + dy[h]])) {  //向四个方向dfs
      vis[i + dx[h]][j + dy[h]] = 1;
      dfs(i + dx[h], j + dy[h], step + 1);
      vis[i + dx[h]][j + dy[h]] = 0;  //回溯
    }
  }
}
