#include <bits/stdc++.h>
//#define LOCAL
#define int long long
using namespace std;

//容斥原理 :ans=只被一个数整除的个数-被2个同时...+被三个.... (奇加偶减)
// 1~n被 p1.p2..pk 同时整除的个数 即 t=p1*p2..*pk的倍数即 n/t
//二进制枚举所有质数选于不选的情况
// O(2^m*m)
const int N = 1e9 + 5;
int m, n, p[20];
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {  // 从0 开始以便位运算
    cin >> p[i];
  }
  int res = 0;
  for (int i = 1; i < 1 << m; i++) {  // 枚举所有情况
    int t = 1, cnt = 0;               //  t为乘积 cnt为1的个数
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) {  //第j位是1
        cnt++;
        if (t * p[j] > n) {  //累乘超过n，该情况不存在，提前中止
          t = -1;
          break;
        }
        //累乘
        t *= p[j];
      }
    }
    if (t != -1) {// 奇加偶减
      if (cnt % 2)
        res += n / t;
      else
        res -= n / t;
    }
  }
    
    cout<<res<<endl;
  
  return 0;
}
