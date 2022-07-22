#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;
// big event in hdu  母函数/多重背包
const int MAX = 250010;
int n, w[55], c[55], a[MAX], b[MAX];
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n, n >=0) {
    for (int i = 1; i <= n; i++) {
      cin >> w[i] >> c[i];
    }
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 0; i <= c[1]; i++) a[i * w[i]] = 1;
    int num = 0;
     num += c[1] * w[1];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= num; j ++)//需要遍历之前每个次数******
        for (int k = 0; k <= c[i + 1] * w[i + 1]; k += w[i + 1])
          b[j + k] += a[j];

      num += c[i + 1] * w[i + 1];

      for (int j = 0; j <= num; j++){
        a[j] = b[j];
        b[j] = 0;
      }
    }
    // for(int i=0;i<=num;i++)
    //   cout<<a[i]<<endl;
    int i;
    for (i = num / 2; a[i] == 0 && i > 0; i--)//找到第一个系数非0的
      ;
    cout << num - i << " " << i << endl;
  }
  return 0;
}
