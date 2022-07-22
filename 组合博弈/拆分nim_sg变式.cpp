#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
// acw894
//拆分nim  ：n后继状态：两堆i j <n  求异或和
//相当于一个局面拆分成了两个局面，由SG函数理论，多个独立局面的SG值，
//等于这些局面SG值的异或和
using namespace std;
const int N = 1005;  //开大
int n, k, a[N];         //  a为取石子方法数
int s[N];
int SG[N];       //记忆化储存sg值
int sg(int x) {  // 记忆化递归
  int vis[N] = {0};
  if (SG[x] != -1) return SG[x];  //已生成直接返回

  for (int i = 0; i < x; i++) {
    for (int j = 0; j <= i; j++) {  // 枚举拆乘的两堆
      int next_SG = sg(i) ^  sg(j); //  每个后继的sg
         //当于一个局面拆分成了两个局面，由SG函数理论，多个独立局面的SG值，
                  //等于这些局面SG值的异或和
      vis[next_SG] = 1;                        //标记后继结点
    }
  }
  for (int i = 0;; i++) {  //求 mex
    if (!vis[i]) return SG[x]=i;
  }
}

signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  memset(SG, -1, sizeof SG);  //  初始化
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    ans ^= sg(m);
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}




//用set  代替标记数组  
// int sg(int x)
// {
//     if (f[x] != -1) return f[x];

//     unordered_set<int> S;
//     for (int i = 0; i < x; i ++ )
//         for (int j = 0; j <= i; j ++ )
//             S.insert(sg(i) ^ sg(j));

//     for (int i = 0;; i ++ )
//         if (!S.count(i))
//             return f[x] = i;
// }