#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize(3)
#define LOCAL
//#define int long long

// edu124 d
//网格给定n 个点，求出每个带你曼哈顿距离最小的非给定n个点一个点
//(答案点可重复)
//思路：将给定点像围棋一样围起来 从这些点向内bfs，即可保证最小
//复杂度：由于每个点最多扩展4个点，而每次放入队列的都是主动的点
//  所以复杂度O(n)  +map(log)
using namespace std;
const int N = 2e5 + 5;
int T, n;
typedef pair<int, int> PII;
int x[N], y[N];
map<PII, int> vis;  //标记
map<PII, int> id;   // 给定点 编号  使能按序输出
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
vector<PII> ans(N);
map<PII, PII> from;  // **(x,y)从外围那个点扩展过来 // 初始位置

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i], id[{x[i], y[i]}] = i;
  queue<PII> que;  //外围点
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 4; k++) {
      int curx = x[i] + dx[k];
      int cury =y[i] + dy[k];
      if (!id.count({curx, cury})) {
        que.push({curx, cury});
        from[{curx, cury}] = {curx, cury};  // 外围起始点
      }
    }
  }
  // bfs();
  while (!que.empty()) {  // 内部全遍历
    PII u = que.front();
    que.pop();
    int x = u.first, y = u.second;
    for (int k = 0; k < 4; k++) {
      int curx = x + dx[k];
      int cury = y + dy[k];
      if (id.count({curx, cury}) && !vis.count({curx, cury})) {  // 向内扩展
        vis[{curx, cury}] = 1;
        from[{curx, cury}] = from[{x, y}];  // 保留起始点(答案)
        ans[id[{curx, cury}]] = from[{curx, cury}];
        que.push({curx, cury});
      }
    }
  }

for(int i=1;i<=n;i++){
  cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
  return 0;
}
