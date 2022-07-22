#include <bits/stdc++.h>
#define LOCAL
#define int long long
//  01 trie   求解最大异或 (固定32位从高位到低位查找)
// 二进制当作字符串插入字典树
using namespace std;
const int N = 1e5 + 5;
int T, n, m;
int tree[N * 32][2];  // 01 字典树
int val[32 * N];      // 每个结点(前缀)的值
int tot = 0;          // 结点编号
void insert(int x) {
  int root = 0;                                   // 空的根节点
  for (int i = 32; i >= 0; i--) {                 // 从高位枚举
    int id = (x >> i) & 1;                        //   每一位二进制
    if (!tree[root][id]) tree[root][id] = ++tot;  //新建结点
    root = tree[root][id];
  }
  val[root] = x;  //记录结点对应的数(前缀)  不存在则为0
}

int find(int x) {  //查找
  int root = 0;
  for (int i = 32; i >= 0; i--) {  // 高到低枚举
    int id = (x >> i) & 1;
    if (tree[root][id ^ 1])
      root = tree[root][id ^ 1];  //找到异或的就异或
    else
      root = tree[root][id];  /// 找不到就将就
  }
  return val[root];  // 查到叶子返回对应的值
}

signed main() {

#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> T;
  int Case = 0;
  while (T--) {
     memset(tree,0,sizeof(tree));
      memset(val,0,sizeof val);
    printf("Case #%d:\n", ++Case);
    scanf("%d %d",&n,&m);
    int a;
    for (int i = 1; i <= n; i++) {
    scanf("%d",&a);
    insert(a);
    }

    for (int i = 1; i <= m; i++) {
      scanf("%d",&a);
      int ans =0; 
      ans= find(a);
      printf("%d\n",ans);
    }
  }
  return 0;
}
