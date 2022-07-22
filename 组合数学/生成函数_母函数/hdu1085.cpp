#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;  //(1+x+x^2+..)(1+x^2+x^4+..)(1+x^5+x^10...)
int a[10000], b[10000];
const int c[3] = {1, 2, 5};
int n[3];

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  while (cin >> n[0] >> n[1] >> n[2], n[0] || n[1] || n[2]) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i <= n[0]; i++) a[i] = 1;  // 1 的倍数次
    int Max = n[0] * c[0];                     //储存最高次
    for (int i = 1; i <= 2; i++) {             //两次乘法 2,5
      for (int j = 0; j <= Max; j++) {
        for (int k = 0; k <= n[i] * c[i]; k += c[i]) {
          b[j + k] += a[j];
        }
      }
      Max += n[i] * c[i];
      for (int j = 0; j <= Max; j++) {
        a[j] = b[j];
      }
    }
    for (int i = 0; i <= Max + 1; i++) {
      if (a[i] == 0) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
