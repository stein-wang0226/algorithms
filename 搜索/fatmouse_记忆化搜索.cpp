#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//记忆化搜索提速
int k, n, Map[1005][1005], ans[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int is_valid(int x, int y) {
  if (x > 0 && x <= n && y > 0 && y <= n) return 1;
  return 0;
}
int dfs(int x, int y) {  //*****返回从(x,y)/*出发*/得到的最大值
  int ret = 0;
  if (ans[x][y]) return ans[x][y];  //已计算过直接返回，***无需重复计算***
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= k; j++) {  //走1~k步
      int cur_x = x + dx[i]*j;//可以走j步
      int cur_y = y + dy[i]*j;
      if (is_valid(cur_x, cur_y)&&Map[cur_x][cur_y]>Map[x][y]) ret = max(ret, dfs(cur_x, cur_y));  //递归搜索
    }
  }
  ans[x][y] = ret + Map[x][y];  //将每次结果储存
  return ans[x][y];
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n >> k && !(k == -1 && n == -1)) {
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++) 
      for (int j = 1; j <= n; j++) cin >> Map[i][j];
   dfs(1,1);
    int answer = ans[1][1];
    cout << answer << "\n";
  }
  return 0;
}
