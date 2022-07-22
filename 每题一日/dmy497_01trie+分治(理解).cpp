#include <bits/stdc++.h>
#define LOCAL
#define int long long
//给定一个长度为n的序列a，找到一个x 10^9x≤10
//让每个a中的元素异或x得到序列b，求b的最小逆序对数以及此时x的取值。
// 异或:某一位0.1互换  字典树的一层同一父亲01交换  ：原本左<右 交换后左>右
// 计算逆序对() ，向下分治
//这个子树中的逆序对的数目，和根节点是0还是1没有关系。 分层计算累加即可
// 先计算每一二进制长度的对数，再计算总对数（易：）
using namespace std;
const int N = 3e5 + 5;
int T, n, m;
int tree[N * 32][2];    // 01 字典树
int tot = 0;            // 结点个数
vector<int> g[32 * N];  // 插入时经过该结点的所有点***
// 类似归并求逆序对
int dp[32][2];  // dp[i][0/1]第i层所有数翻转与否产生的逆序对数
void insert(int x, int idx) {      // pos ,当前插入数的编号
  int root = 0;                    // 空的根节点
  for (int i = 29; i >= 0; i--) {  // 从高位枚举
    int bit = (x >> i) & 1;  // 这一位0/1                       // 每一位二进制
    if (!tree[root][bit]) tree[root][bit] = ++tot;  //新建结点
    root = tree[root][bit];
    g[root].push_back(idx);
  }
}
//  idx原编号  tot 树中编号(去重)
// 同一结点
void cal(int fa, int bit) {              // 分治计算每对儿子逆序对
  int L = tree[fa][0], R = tree[fa][1];  // 左右儿子在数中编号
  if (L) cal(L, bit - 1);                //下一层左儿子
  if (R) cal(R, bit - 1);
  int res = 0;           //^0 不交换的对数
  for (auto t : g[L]) {  //   此处优化
    int i=0;
    while (i < g[R].size() && t > g[R][i]) i++; res+=i;   // 不这样会t
  }
  dp[bit][0] += res;
  dp[bit][1] += (g[L].size() * g[R].size()) - res;  // 减去即为正序
}  // 类似归并  分治将树中每对都计算
// 每一层都能取最优
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    insert(a, i);
  }
  cal(0, 29);  // 1e9
  int cnt = 0, num = 0;
  for (int i = 0; i <= 29; i++) {
    cnt += min(dp[i][0], dp[i][1]);            // 每一层都能取最优
    if (dp[i][1] < dp[i][0]) num += (1 << i);  //需要1来异或
  }

  cout << cnt << " " << num << endl;
  return 0;
}
