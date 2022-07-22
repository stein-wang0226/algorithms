#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n;
string s[25];
int vis[25];       //可出现两次
int vis2[25][25];  //记忆化
char a;
int ans = 0;
int len[25][25];  //重叠长度
int islink(int a, int b) {
  if (vis2[a][b]) return len[a][b];  //
  int m = min(s[a].size(), s[b].size());
  for (int i = 1; i < m; i++) {
    if (s[a].substr(s[a].size() - i, i) == s[b].substr(0, i)) {
      len[a][b] = i;
      return 1;
    }
  }
  return 0;
}
void dfs(int k, int ret) {
  ans = max(ans, ret);

  for (int i = 1; i <= n; i++) {
    if (vis[i] && islink(k, i)) {
      vis[i]--;
      dfs(i, ret + s[i].size() - len[k][i]);
      vis[i]++;  //
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  cin >> a;
  for (int i = 1; i <= n; i++) vis[i] = 2;
  memset(vis2, 0, sizeof vis2);
  for (int i = 1; i <= n; i++) {
    if (s[i][0] == a) {
      vis[i]--;
      dfs(i, s[i].size());
    vis[i]++;
    }
  }
  cout << ans << endl;
  return 0;
}
