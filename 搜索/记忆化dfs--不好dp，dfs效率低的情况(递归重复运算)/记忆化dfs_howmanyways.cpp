#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//记忆化搜索提速
int m, n, t, Map[105][105], ans[105][105];
int is_valid(int x, int y) {
  if (x > 0 && x <= n && y > 0 && y <= m) return 1;
  return 0;
}
int dfs(int x, int y) {  //*****返回从(x,y)/*出发*/得到的次数
  int cur_x, cur_y;
  if (ans[x][y]) return (ans[x][y]%10000);//已搜过则直接返回，防止重复计算
  for (int dx = 0; dx <= Map[x][y]; dx++) {
    for (int dy = 0; dy <= Map[x][y]-dx; dy++) {
           cur_x = x + dx;
           cur_y = y + dy;
           if (dx + dy <= Map[x][y] && dx+dy>0&&is_valid(cur_x,cur_y)) {//防止原地踏步****(dx==dy==0)
             ans[x][y] +=( dfs(cur_x, cur_y)%10000);
      }
    }
  }
  return (ans[x][y]%10000);
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> Map[i][j];
    ans[n][m] = 1;  //到终点则加1
    dfs(1, 1);
    int answer = ans[1][1]%10000;
    cout << answer << "\n";
  }
  return 0;
}
