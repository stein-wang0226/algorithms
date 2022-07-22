#include <bits/stdc++.h>  //sg函数模板题--组合游戏的组合
// x点的sg值是 去除 x的 后继节点的sg值后的最小正整数
  //记忆化递归+sg函数
#define LOCAL
using namespace std;
int SG[10005];
int k, m, n, s, a[105];  //注意变量含义
int sg(int t) {  //找 去除 t的 后继节点的sg值后的最小正整数
  int vis[105] = {0};  //记录后继结点的sg值
  if (SG[t] != -1) return SG[t];  //已生成过无需计算 //未生成过再算，减少计算
  for (int i = 1; i <= k; i++) {
    int next = t - a[i];  //后继结点  取a[i]~a[k]  
    if (next < 0) break;//已sort  未sort则continue,,c. 
    if (SG[next] == -1) SG[next] = sg(next);  //后继节点未生成则向前递归 储存
    vis[SG[next]] = 1;                        //标记所有后继节点
  }
  for (int i = 0;; i++) {   //从小开始
    if (!vis[i]) return i;  //不是后继节点的sg值直接返回
  }
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> k, k) {  // k 为拿取的可能数
    for (int i = 1; i <= k; i++) cin >> a[i];
    sort(a+1,a+1+k);//****,减少计算  
    memset(SG,-1,sizeof SG);//未计算过初始化-1方便记忆化递归
    cin >> n;     // n为该情况数据组数
    int ans = 0;  // 0^n=n;
    while (n--) {
      cin >> m;
      ans = 0;
      while (m--) {  // m为该组数据长度
        cin >> s;
        if (SG[s] == -1) SG[s] = sg(s);  //此行可能减少一次调用
        ans = ans ^ SG[s];
      }
      if (ans)
        cout << "W";
      else
        cout << "L";
    }

    cout << "\n";
  }
  return 0;
}
