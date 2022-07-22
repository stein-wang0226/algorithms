#include <stdio.h>
//  区间和并  +线段树
#include <cstring>
#include <iostream>
#define LOCAL
using namespace std;
const int MAX = 1e5 + 100;
int t, m, n, a[MAX];
int Max(int a, int b, int c) {
  return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
// 单点修改 求区间lci  区间合并
// 对于任意一个区间：max是整个区间的lcis，lmax是从当前节点最左端开始的lcis长，rmax是从最右端..
// 1.  左子区间最右端>=右子区间最左边 （不能相连）
//   max=max(左子区间max,右子区间max)
// 2. 左子区间最右端<右子区间最左边  (可相连)
//   lmax=(左子区间lmax==左子区间长度len)?左子区间len+右子区间lmax:左子区间lmax
//   rmax=(右子区间rmax==右子区间长度len)?右子区间len+左子区间rmax:右子区间rmax
// max= max(左子区间max，右子区间max,左子区间rmax+右子区间lmax)
struct segtreenode {
  int lmax, max, rmax, vall, valr, len;

} segtree[MAX << 2];   //定义原数组大小四倍的线段数组
void pushup(int rt) {  //区间合并操作
  segtree[rt].vall = segtree[rt << 1].vall;
  segtree[rt].valr = segtree[rt << 1 | 1].valr;
  segtree[rt].len = segtree[rt << 1].len + segtree[rt << 1 | 1].len;
  if (segtree[rt << 1].valr < segtree[rt << 1 | 1].vall) {  //可相连
    segtree[rt].lmax = (segtree[rt << 1].lmax == segtree[rt << 1].len)
                           ? segtree[rt << 1].len + segtree[rt << 1 | 1].lmax
                           : segtree[rt << 1].lmax;
    segtree[rt].rmax = (segtree[rt << 1 | 1].rmax == segtree[rt << 1 | 1].len)
                           ? segtree[rt << 1 | 1].len + segtree[rt << 1].rmax
                           : segtree[rt << 1 | 1].rmax;
    segtree[rt].max = Max(segtree[rt << 1].max, segtree[rt << 1 | 1].max,
                          segtree[rt << 1].rmax + segtree[rt << 1 | 1].lmax);
  } else {
    segtree[rt].lmax = segtree[rt << 1].lmax;
    segtree[rt].rmax = segtree[rt << 1 | 1].rmax;
    segtree[rt].max = max(segtree[rt << 1].max, segtree[rt << 1 | 1].max);
  }
}
void build(int l, int r, int rt) {  // 递归构造线段树
  if (l == r) {  //出口  左右相等 为叶子节点则停止向下递归
    segtree[rt].vall = segtree[rt].valr = a[l];  //叶子节点的l,r即位置下标
    segtree[rt].max = segtree[rt].lmax = segtree[rt].rmax = 1;
    segtree[rt].len = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, rt * 2);  //递归构造左子树 根序号为2*rt ,2*tr+1
  build(mid + 1, r, rt * 2 + 1);  //递归构造右子树
  pushup(rt);  //** 回溯,当左右子树都构造完后向上加到根节点
}

//单点更新，
void updateNode(int t, int c, int l, int r,
                int rt) {  // l,r 表示当前节点区间，rt表示当前根节点编号
  if (l == r) {
    segtree[rt].vall = segtree[rt].valr = c;  //    叶子节点  直接修改
    return;
  }
  int mid = (l + r) / 2;
  if (t <= mid)
    updateNode(t, c, l, mid, rt << 1);  //更新左子树
  else
    updateNode(t, c, mid + 1, r, rt << 1 | 1);
  pushup(rt);  //回溯向上更新，相加
}

//区间查询  [L,R]为操作区间,[l,r]为当前区间，rt为节点编号
int query(int L, int R, int l, int r, int rt) {
  int ans = 0;
  if (L <= l && r <= R) return segtree[rt].max;  //当前区间被包含 则直接返回

  if (L > r || R < l)  //当前区间全部不重和，则返回0，而且其子区间也不会包含
    return 0;
  //否则部分包含  向下递归
  int mid = (l + r) / 2;
  ans = max(query(L, R, l, mid, rt << 1),
            query(L, R, mid + 1, r, rt << 1 | 1));  //不相连的答案
  if (segtree[rt << 1].valr >= segtree[rt << 1 | 1].vall) {  //不相连
    return ans;
  }
  //处理相连
  ans = max(ans, min(mid - L + 1, segtree[rt << 1].rmax) +
                     min(segtree[rt << 1 | 1].lmax, R - mid));
  return ans;
}  // min的作用：只截取L，R区间的最大情况 ***关键 ，否则每次都输出全部的最大情况

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(a, 0, sizeof a);
    memset(segtree, 0, sizeof segtree);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    build(1, n, 1);
    while (m--) {
      int A, b;
      char c;
      cin >> c >> A >> b;
      if (c == 'U') {
        updateNode(A + 1, b, 1, n, 1);
      } else {
        int ret = query(A + 1, b + 1, 1, n, 1);
        cout << ret << endl;
      }
    }
  }
  return 0;
}
