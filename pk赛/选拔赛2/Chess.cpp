#include <bits/stdc++.h>
#define N 107
#define mod 19260817
using namespace std;
typedef long long ll;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) 
        if (c == '-') f = 1;
    for(; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

struct matrix {
  
  int m, n;
  
  int a[N][N];

  inline void init(int _m = 0, int _n = 0) {
    m = _m; n = _n;
    memset(a, 0, sizeof(a));
  }

  inline matrix operator * (matrix B) {
    matrix res;
    res.init(m, B.n);
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= B.m; ++j)
        for (int k = 1; k <= n; ++k)
          res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * B.a[k][j] % mod) % mod; 
    return res;
  }

  inline void id() {
    for (int i = 1; i <= m; ++i) a[i][i] = 1;
  }

  inline matrix fpow(ll t) {
    matrix res; 
    res.init(n, n); res.id();
    matrix tmp = *this;
    for(; t; t >>= 1, tmp = tmp * tmp)
      if (t & 1) res = res * tmp;
    return res;
  }

}S;

int n, m;

int pos(int x, int y) {
  return x + (y - 1) * n;
}

inline void build_rook() {
  for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= m; ++y) {
      int nw = pos(x, y);
      for (int i = 1; i <= n; ++i)
        if (i != x) {
          int t = pos(i, y);
          ++S.a[nw][t]; 
        }
      for (int i = 1; i <= m; ++i) 
        if (i != y) {
          int t = pos(x, i);
          ++S.a[nw][t];
        }
    }
}

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};

const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

inline void build_knight() {
  for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= m; ++y) {
      int nw = pos(x, y);
      for (int i = 0; i <= 7; ++i) {
          int tx = x + dx[i];
          int ty = y + dy[i];
          if (tx <= 0 || ty <= 0 || tx > n || ty > m) continue; 
          int t = pos(tx, ty);
          ++S.a[nw][t];
        }
    }
}

const int Dx[4] = {2, 2, -2, -2};

const int Dy[4] = {2, -2, 2, -2};

inline void build_bishop() {
  for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= m; ++y) {
      int nw = pos(x, y);
      for (int i = 0; i <  4; ++i) {
          int tx = x + Dx[i];
          int ty = y + Dy[i];
          if (tx <= 0 || ty <= 0 || tx > n || ty > m) continue; 
          int t = pos(tx, ty);
          ++S.a[nw][t];
        }
    }
}

inline void work() {
  int op = rd();
  n = rd(); m = rd();
  S.init(n * m, n * m);
  int sx = rd(); 
  int sy = rd();
  if (op == 0) build_rook();
  if (op == 1) build_knight();
  if (op == 2) build_bishop();
  S = S.fpow(rd());
  ll ans = 0;
  int s = pos(sx, sy);
  for (int i = 1; i <= n * m; ++i)
    ans = (ans + S.a[s][i]) % mod;
  printf("%lld\n", ans);
}

int main() {
    int t = rd();
    while (t--) work();
    return 0;
}