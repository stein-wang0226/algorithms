#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define tii tuple<int, int, int>

#define M 500007
#define mod 1000000007

inline int fpow(int x, int t = mod - 2) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

inline void add(int &a, int b) {a = a + b - (a + b >= mod) * mod;}

int testcase, fac[M], ifac[M], g[M] = {1}, f[M], pw[M];

inline int C(int n, int m) {
    if (m > n) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

inline void work() {
    int n = rd(), k = rd();
    for (int i = 1; i <= n; ++i)
        g[i] = 1ll * g[i - 1] * fpow((C(n, 2) - C(n - 2 * i, 2) + mod) % mod) % mod;
    for (int i = 1; i <= n / 2; ++i) {
        g[i] = 1ll * g[i] * fac[i] % mod * fpow(1ll * fac[i] * pw[i] % mod) % mod;
        g[i] = 1ll * g[i] * fac[n] % mod * fpow(fac[n - 2 * i]) % mod;
    }
    int ans = 0;
    for (int i = k; i <= n / 2; ++i) {
        int w = 1ll * C(i, k) * g[i] % mod;
        if ((i - k) & 1) w = mod - w;
        ans = (ans + w) % mod;
    }
    printf("%d\n", ans);
}

int main() {
    fac[0] = ifac[0] = pw[0] = 1;
    for (int i = 1; i < M; ++i) {
        pw[i] = pw[i - 1] * 2 % mod;
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    ifac[M - 1] = fpow(fac[M - 1]);
    for (int i = M - 2; i; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

    for (int t = rd(); t; --t) work();
    return 0;
}