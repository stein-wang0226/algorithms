#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

int T, n, a[N];
struct Node {
  int x, y;
  bool operator<(const Node& b) {
    return x < b.x;  //按x排序
  }
} node[5];

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= 3; i++) {
    cin >> node[i].x >> node[i].y;
  }
  sort(node + 1, node + 1 + 3);
  if (node[1].y <= node[2].y && node[2].y <= node[3].y ||
      node[1].y >= node[2].y && node[2].y >= node[3].y) {
    int cnt = 4;
        if (node[1].x == node[2].x)cnt--;
        if (node[1].y == node[2].y)cnt--;
        if (node[2].x == node[3].x)cnt--;
      if (node[2].y == node[3].y)cnt--;
    // int a1,a2,b1,b2;
     cout << cnt << endl;
    if (node[1].x != node[2].x)
      cout << node[1].x << " " << node[1].y << " " << node[2].x << " "
           << node[1].y << endl;

    if (node[1].y != node[2].y)
      cout << node[2].x << " " << node[1].y << " " << node[2].x << " "
           << node[2].y << endl;

    if (node[2].x != node[3].x)
      cout << node[2].x << " " << node[2].y << " " << node[3].x << " "
           << node[2].y << endl;

    if (node[2].y != node[3].y)
      cout << node[3].x << " " << node[2].y << " " << node[3].x << " "
           << node[3].y << endl;

  }

  else {  //不单调  先两条边最高点和最低点  中间的平行于y轴
    if (node[2].y >= node[1].y && node[2].y >= node[3].y) {
      //最高  --最低
      if (node[1].y <= node[3].y) {  // 2 1
        int cnt = 3;
        if (node[1].x == node[2].x)cnt--;
        if (node[1].y == node[2].y)cnt--;
        if (node[2].x == node[3].x && node[2].y == node[3].y)cnt--;
        cout << cnt << endl;

        if (node[1].x != node[2].x)
          cout << node[1].x << " " << node[1].y << " " << node[2].x << " "
               << node[1].y << endl;

        if (node[1].y != node[2].y)
          cout << node[2].x << " " << node[1].y << " " << node[2].x << " "
               << node[2].y << endl;

        if (node[2].x != node[3].x || node[2].y != node[3].y)
          cout << node[3].x << " " << node[3].y << " " << node[2].x << " "
               << node[3].y << endl;

      } else {
        int cnt = 3;
        if (node[3].x == node[2].x)cnt--;
        if (node[3].y == node[2].y)cnt--;
        if (node[2].x == node[1].x && node[2].y == node[1].y)cnt--;
        cout << cnt << endl;
        if (node[3].x != node[2].x)
          cout << node[3].x << " " << node[3].y << " " << node[2].x << " "
               << node[3].y << endl;

        if (node[3].y != node[2].y)
          cout << node[2].x << " " << node[3].y << " " << node[2].x << " "
               << node[2].y << endl;

        if (node[2].x != node[1].x || node[2].y != node[1].y)
          cout << node[1].x << " " << node[1].y << " " << node[2].x << " "
               << node[1].y << endl;

      }

    } else {
      //最低  最高
      if (node[1].y >= node[3].y) {  // 2 1
        int cnt = 3;
        if (node[1].x == node[2].x)cnt--;
        if (node[1].y == node[2].y)cnt--;
        if (node[2].x == node[3].x && node[2].y == node[3].y)cnt--;
        cout << cnt << endl;

        if (node[1].x != node[2].x)
          cout << node[1].x << " " << node[1].y << " " << node[2].x << " "
               << node[1].y << endl;

        if (node[1].y != node[2].y)
          cout << node[2].x << " " << node[1].y << " " << node[2].x << " "
               << node[2].y << endl;

        if (node[2].x != node[3].x || node[2].y != node[3].y)
          cout << node[3].x << " " << node[3].y << " " << node[2].x << " "
               << node[3].y << endl;

      } else {
        int cnt = 3;
        if (node[3].x == node[2].x)cnt--;
        if (node[3].y == node[2].y)cnt--;
        if (node[2].x == node[1].x && node[2].y == node[1].y)cnt--;
        cout << cnt << endl;
        if (node[3].x != node[2].x)
          cout << node[3].x << " " << node[3].y << " " << node[2].x << " "
               << node[3].y << endl;

        if (node[3].y != node[2].y)
          cout << node[2].x << " " << node[3].y << " " << node[2].x << " "
               << node[2].y << endl;

        if (node[2].x != node[1].x || node[2].y != node[1].y)
          cout << node[1].x << " " << node[1].y << " " << node[2].x << " "
               << node[1].y << endl;

      }
    }
  }
  return 0;
}
