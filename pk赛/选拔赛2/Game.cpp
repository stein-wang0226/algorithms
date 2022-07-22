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

inline int gc() {
    char c = getchar();
    for (; c != '.' && c != 'X'; c = getchar());
    return c == 'X';
}

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

#define N 107
#define pb push_back

bool a[2][N][N];

unordered_map<ll, int> sg;

inline ll hash_scope(ll id, ll a, ll b, ll c, ll d) {
    return (((a * 200 + b) * 200 + c) * 200 + d) * 2 + id;
}

int dp(int id, int lx, int rx, int ly, int ry) {
    if (lx > rx || ly > ry) return 0;
    ll h = hash_scope(id, lx, rx, ly, ry);
    if (sg.find(h) != sg.end()) return sg[h];
    vector<int> nxt; nxt.clear();
    for (int x = lx; x <= rx; ++x)
        for (int y = ly; y <= ry; ++y)
            if (a[id][x][y]) {
                int a = dp(id, lx, x - 1, ly, y - 1);
                int b = dp(id, lx, x - 1, y + 1, ry);
                int c = dp(id, x + 1, rx, ly, y - 1);
                int d = dp(id, x + 1, rx, y + 1, ry);
                nxt.pb(a ^ b ^ c ^ d);
            }
    sort(nxt.begin(), nxt.end());
    for (int i = 0, ptr = 0; ; ++i) {
        if (ptr >= nxt.size() || nxt[ptr] > i) return sg[h] = i;
        for (; ptr < nxt.size() && nxt[ptr] == i; ++ptr);
    }
}

inline void work() {
    sg.clear();
    memset(a, 0, sizeof(a));
    int r = rd(), c = rd();
    int lx = 1e9, ly = 1e9;
    int rx = -1e9, ry = -1e9;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            int id = ((i + j) & 1);
            int x = (i + j) / 2;
            int y = (i - j + 100) / 2;
            if ((a[id][x][y] = gc())) {
                lx = min(lx, x); rx = max(rx, x); 
                ly = min(ly, y); ry = max(ry, y);
            }
        }
    int ans = 0, cnt = 0;
    for (int id = 0; id <= 1; ++id)
        for (int x = lx; x <= rx; ++x)
            for (int y = ly; y <= ry; ++y)
                if (a[id][x][y]) {
                    ++cnt;
                    int a = dp(id, lx, x - 1, ly, y - 1);
                    int b = dp(id, lx, x - 1, y + 1, ry);
                    int c = dp(id, x + 1, rx, ly, y - 1);
                    int d = dp(id, x + 1, rx, y + 1, ry);
                    ans += ((a ^ b ^ c ^ d ^ dp(id ^ 1, lx, rx, ly, ry)) == 0);
                }
    ans = cnt - ans;
    int g = gcd(ans, cnt);
    printf("%d %d\n", ans / g, cnt / g);
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}