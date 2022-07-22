#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//模拟散列表  I 插入   Q查询是否出现过
// 1 拉链法
int n;
const int N = 1e5 + 3;  //接近的质数
int h[N];               //槽   h[n] 对应的哈希值
int e[N], ne[N], idx;   //单链表  元素值  指针 序号

void insert(int x) {        //插入到尾部（与槽连接处）
  int k = (x % N + N) % N;  //防止负数
  e[idx] = x;   //链表插入操作  将x的值存放到 h[k]的拉链中
  ne[idx] = h[k];
  h[k] = idx++;
}
bool find(int x) {
  int k = (x % N + N) % N;
  for (int i = h[k]; i != -1; i = ne[i]) {  //访问整个链表
    if (e[i] == x) return 1;                //找到
  }
  return 0;  //未找到
}
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  idx = 0;
  memset(h, -1, sizeof h);
  cin >> n;
  string s;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> s >> x;
    if(s=="I")insert(x);
    else {
        if(find(x))puts("Yes");
        else puts("NO");
    }
  }
  return 0;
}
