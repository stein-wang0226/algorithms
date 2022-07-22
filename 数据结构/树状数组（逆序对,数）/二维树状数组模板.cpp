#include <bits/stdc++.h>
#define LOCAL
using namespace std;
// 二维树状数组
//大意：把一个房间划分成一个矩阵，其中的每个放个都可以放书，且每个方格初始都有一本书，接下来有四种操作：
// S x1 y1 x2 y2是询问a[x1][y1]到a[x2][y2]直接有多少本书，
// A x1 y1 n1意思是向a[x1][y1]中放n1本书，
// D x1 y1 n1意思是从a[x1][y1]中拿出n1本书，如果不足则全部拿出。
// M x1 y1 x2 y2
// n1意为从a[x1][y1]中拿出n1本书放到a[x2][y2]中，若不足则全部拿出。
const int MAX = 1005;
int t, n;
int c[MAX][MAX];
int a[MAX][MAX];
int lowbit(int x) { return x & -x; }
void update(int x, int y, int val) {  //就是一维嵌套
  for (int i = x; i <= 1001; i += lowbit(i)) {
    for (int j = y; j <= 1001; j += lowbit(j)) {
      c[i][j] += val;
    }
  }
}
int sum(int x, int y) {  //求和区间查询同理
  int ans = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j -= lowbit(j)) {
      ans += c[i][j];
    }
  }
  return ans;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  int cnt = 0;
  while (t--) {
    printf("Case %d:\n", ++cnt);
    cin >> n;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= 1001; i++) {  //全部初始化为1
      for (int j = 1; j <= 1001; j++) {
        update(i, j, 1);
        a[i][j] = 1;
      }
    }
    while (n--) {
      char C;
      cin >> C;
      if (C == 'A') {
        int x, y, val;
        cin>>x>>y>>val;
        a[x+1][y+1] += val;
        update(x + 1, y + 1, val);
      }
      else if (C == 'D') {
        int x, y, val;
        cin >> x >> y >> val;
        val = min(val, a[x + 1][y + 1]);
        a[x + 1][y + 1] -= val;  //
        update(x + 1, y + 1, -val);
      }
      else if (C== 'M') {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        val = min(val, a[x1 + 1][y1 + 1]);  //同理
        a[x1 + 1][y1 + 1] -= val;         //
        a[x2+1][y2+1]+=val;
        update(x1 + 1, y1 + 1, -val);
        update(x2 + 1, y2 + 1, val);
      }
      else if (C == 'S') {  //画图易得
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++;
        x2++;
        y1++;
        y2++;  //先自增算了
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        //二维求得是一个矩阵的和，划一下图就知道为什么要这样写了，用总的减去左边和右边不要的，然后再加上多减的一个矩阵
        printf("%d\n", sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +sum(x1 - 1, y1 - 1));
                           
      }
    }
  }
  return 0;
}
