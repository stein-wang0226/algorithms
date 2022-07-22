/*1，无环；(有向图->根唯一)
2，除了根，所有的入度为1，根入度为0；
3，这个结构只有一个根，不然是森林了。再注意这里空树也是树。
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int a, b,cnt=0;
int pre[MAX];  ///并查集记录父亲节点
int in[MAX];   ///入度
int vis[MAX];  ///节点是否存在
void init() {
  for (int i = 1; i <= MAX; i++) {
    pre[i] = i;
  }
}
int find_r(int x) {  //寻找根节点
  while (pre[x] != x) {
    x = pre[x];
  }
  return x;
}
void merge(int x, int y) {
  int root_x = find_r(x);
  int root_y = find_r(y);
  if (root_x != root_y) {
    pre[root_x] = root_y;
  }
}
int main() {
  while (1) {
    int flag = 1;
    cnt++;
    memset(vis, 0, sizeof vis);
    memset(in, 0, sizeof in);
    init();
    int Flag=1;
    while (~scanf("%d %d", &a, &b) && a && b)  //每次读到00为止
    {
      if (a < 0 || b < 0) return 0;  // a和b为负数时，结束程序
	  vis[a] = 1;
      vis[b] = 1;
      in[b]++;
      merge(a, b);  //
    }
    int cnt1 = 0, cnt2 = 0;  //根数  集合数
    for (int i = 1; i <= MAX; i++) {
      if (vis[i] && in[i] == 0) cnt1++;  //根数
      if (vis[i] && find_r(i) == i) cnt2++;
      if (in[i] >= 2)  ///除根节点外，其他点入度需为1
      {
        flag = 0;
      }
    }
    if (!(cnt1 == 1 && cnt2 == 1) )flag = 0;
    if (flag)
     printf("Case %d is a tree.\n",cnt);
    else
    printf("Case %d is not a tree.\n",cnt);
  }
  return 0;
}
