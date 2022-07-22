#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;
int t, n, k;
int a[650], b[650];
int w[20], c[20];
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> w[i] >> c[i];

    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (int i = 0; i <= c[1]; i++) a[i * w[1]] = 1;
    int num = 0;
    num += w[1] * c[1];
    for (int i = 1; i < k; i++) {
      for (int j = 0; j <= num; j ++)//需要遍历之前每个次数
        for (int k = 0; k <= w[i + 1] * c[i + 1]&&k+j<=n;k+=w[i+1]) {
          b[j + k] += a[j];
        }
      num += c[i + 1] * w[i + 1];
      for (int j = 0; j <= num; j++) {
        a[j] = b[j];
        b[j] = 0;
      }
    }
 cout<<a[n]<<endl;
  }
  return 0;
}
