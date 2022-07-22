#include <bits/stdc++.h>
#define LOCAL
////堆贪心，每次从当前堆中取出高度最小的塔，将当前块加上去即可。证明如下：
//当有两个塔高度相差超过x时，因为每个块的高度小于x，因此相差的必定为两个块以上，
//而由贪心策略每次都是往最矮的塔上面放，
//不可能出现相差两个块的情况（模拟一下易知）。//优先队列
//必然有解
//没看到 h<x 导致想不到解法
using namespace std;
int t, n, m, x;
const int MAX = 1e5 + 5;
int h[MAX], ans[MAX];
struct node {
  int id, h;
  bool operator<(const node& b) const {
    return h > b.h;  //相反
  }
} a[MAX];

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> m >> x;
    priority_queue<node> que;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].h;
      a[i].id = i;
    }

    for (int i = 1; i <= m; i++) {
      que.push({i, 0});
    }
    for (int i = 1; i <= n; i++) {  //
      node cur = que.top();
      que.pop();
      cur.h += a[i].h;
      ans[i] = cur.id;  //
      que.push(cur);
    }
    while (!que.empty()) {
      node cur = que.top();
      que.pop();
    }
    cout << "yes" << endl;//必有解
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
