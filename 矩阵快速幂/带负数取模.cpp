#include <bits/stdc++.h>
#define LOCAL
using namespace std;
long long t, a2, n, mod;
// an=2*a2*an-1-an-2
//求平方和 an^2

// 负数取模    ((n%mod)+mod)%mod
struct Matrix {
  long long matrix[5][5];
} ori, res;
void init() {
  memset(ori.matrix, 0, sizeof ori.matrix);
  memset(res.matrix, 0, sizeof res.matrix);
  for (int i = 1; i <= 4; i++) res.matrix[i][i] = 1;
  ori.matrix[1][1] = ori.matrix[3][2] = ori.matrix[1][3] = ori.matrix[2][3] = 1;
  ori.matrix[1][2] = ori.matrix[2][2] = (4 * (a2 * a2)%mod) % mod;
  ori.matrix[1][4] = ori.matrix[2][4] = ((-4 * a2) % mod + mod) % mod;
  ori.matrix[4][2] = (2 * a2) % mod;
  ori.matrix[4][4] = -1 + mod;
}
Matrix mul(Matrix a, Matrix b) {
  Matrix ret;
  memset(ret.matrix, 0, sizeof ret.matrix);
  for (int i = 1; i <= 4; i++) {
    for (int k = 1; k <= 4; k++) {
      if(a.matrix[i][k])
      for (int j = 1; j <= 4; j++) {
        ret.matrix[i][j] = (ret.matrix[i][j]+(a.matrix[i][k]  )* (b.matrix[k][j]))% mod ;
      }
    }
  }
  return ret;
}

void ksm(Matrix a, long long k) {
  while (k) {
    if (k & 1) res = mul(res, a);

    a = mul(a, a);
    k >>= 1;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> a2 >> n >> mod;
    if (n == 1) {
      cout <<"1"<< endl;
      continue;
    }
    if (n == 2) {
      cout << (1 + a2 * a2)%mod << endl;//不要忘了取模 555
      continue;
    }
    if (a2 == 1) {
      cout << n % mod << endl;
      continue;
    }
    long long result[5] = {0, (1 + a2 * a2)%mod, (a2 * a2)%mod, 1, a2};//取模防溢出
    init();
    ksm(ori, n - 2);
    long long ans = 0;
    for (int i = 1; i <= 4; i++) {
      ans += (res.matrix[1][i] * (result[i])) % mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
