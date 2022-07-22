#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
// D2首先，不同的数异或x后结果不同  所以a中数肯定不同
// 现在只需要保证a中结果全<r &&>l 即可
//枚举x
// 用01字典树跑异或最大值
//枚举x：枚举x= a[i]^l   因为肯定有一个a[i]满足x^a[i]=l
const int N = 5e5 + 5;

int T, n, a[N], l, r;
int tree[N * 32][2];
int val[32 * N];  //  叶子对应值
int tot;
void init() {
  tot = 0;
  tree[0][0]=tree[0][1]=0;
}
void insert(int x) {
  int root = 0;
  for (int i = 20; i >= 0; i--) {
    int id = (x >> i) & 1;  // 二进制位的值
    if (!tree[root][id]) {
          // 过程中初始化
      tree[root][id] = ++tot;
      tree[tot][0]=tree[tot][1]=0;
    }  
    root = tree[root][id];
  }
  val[root] = x;  // 叶子存值
}

int find_max(int x) {  // 查找max
  int root = 0;
  for (int i = 20; i >= 0; i--) {
    int id = (x >> i) & 1;
    if (tree[root][id ^ 1])
      root = tree[root][id ^ 1];
    else
      root = tree[root][id];
  }
  return val[root] ^ x;  // 返回最大异或值
}

int find_min(int x) {  // 查找min  相反即可
  int root = 0;
  for (int i = 20; i >= 0; i--) {
    int id = (x >> i) & 1;
    if (tree[root][id])
      root = tree[root][id];
    else
      root = tree[root][id ^ 1];
  }
  return val[root] ^ x;  // 返回最大异或值
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    init();
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      cin >> a[i];
      insert(a[i]);
    }
    for (int i = l; i <= r; i++) {
      int x = a[i] ^ l;  //枚举x
      if (find_max(x) == r && find_min(x) == l) {
        cout << x << endl;
        break;
      }
    }
  }

  return 0;
}
