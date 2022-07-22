#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LOCAL
using namespace std;
//递推式  :f(n)=2*f(n-2)+f(n-1)+n^3;
//含变量   n^3=(n-1)^3+3*(n-1)^2+3*(n-1)+1
#define ull unsigned long long
const ull mod = 123456789;
int t;
ull n;
struct Matrix {
  int matrix[10][10];
} ori, res;
int data[][8] = {{0, 0, 0, 0, 0, 0, 0}, {0, 1, 2, 1, 3, 3, 1},
                 {0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 3, 3, 1},
                 {0, 0, 0, 0, 1, 2, 1}, {0, 0, 0, 0, 0, 1, 1},
                 {0, 0, 0, 0, 0, 0, 1}};
int b[7] = {0, 2, 1, 8, 4, 2, 1};  //最后乘的结果

void init() {
  memset(res.matrix, 0, sizeof res.matrix);
  for (int i = 1; i <= 6; i++) {
    res.matrix[i][i] = 1;  //单位阵
  }
}

Matrix mul(Matrix a, Matrix b) {
  Matrix ret;
  memset(ret.matrix, 0, sizeof ret.matrix);
  for (int i = 1; i <= 6; i++) {
    for (int k = 1; k <= 6; k++) {
      if(a.matrix[i][k])
      for (int j = 1; j<= 6; j++) {
        ret.matrix[i][j] += ((a.matrix[i][k])%mod* (b.matrix[k][j])%mod)%mod;//都取模防溢出
         ret.matrix[i][j] %= mod;
      }
    }
  }
  return ret;
}

void ksm(Matrix a, ull k) {
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
   for (int i = 1; i <= 6; i++) {//ori 矩阵不变，不需每次初始化
    for (int j = 1; j <= 6; j++) {
      ori.matrix[i][j] = data[i][j];
    }
  }
  while (t--) {
    cin >> n;
    if (n <= 2) {
      cout << n << endl;
    } else {
      ull ans = 0;
      init();
      ksm(ori, n - 2);
      for (int i = 1; i <= 6; i++) {
        ans += (res.matrix[1][i] * b[i])%mod;
        ans%=mod;
      }
      cout << ans%mod<< endl;
    }
  }
  return 0;
}
