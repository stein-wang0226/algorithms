#include <cstdio>
#include <ctime>
#include<cstring>
#include <iostream>
#define LOCAL
using namespace std;
int m, n, dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
          dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt = 0;
char Map[105][105];
int is_valid(int x, int y) {
  if (x > 0 && x <= m && y > 0 && y <= n) return 1;
  return 0;
}
void dfs(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int cur_x = x + dx[i];
    int cur_y = y + dy[i];
    if (is_valid(cur_x, cur_y)&&Map[cur_x][cur_y]=='@') {
      Map[cur_x][cur_y]='*';//***标记技巧
     dfs(cur_x, cur_y);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  clock_t c1 = clock();
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  while (cin >> m >> n && m && n) {
    cnt = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> Map[i][j];
      }
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (Map[i][j] == '@') {
          Map[i][j]='*';// 标记
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
