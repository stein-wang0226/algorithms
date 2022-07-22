#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 200007
#define fr first
#define sc second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mp make_pair
#define mid ((l + r) >> 1)
#define pii pair<int, int>

vector<int> son[N];

int cnt, dfn[N], dep[N], rdfn[N], fa[N], sz[N];

void dfs(int u) {
    dfn[u] = ++cnt;
    sz[u] = 1;
    for (auto v : son[u]) {
        dep[v] = dep[u] + 1;
        dfs(v); 
        sz[u] += sz[v];
    }
}

pii mx[N << 2];

int fl[N << 2];

inline void pushdown(int rt) {
    if (fl[rt]) {
        fl[ls] += fl[rt];
        fl[rs] += fl[rt];
        mx[ls].fr += fl[rt];
        mx[rs].fr += fl[rt];
        fl[rt] = 0;
    }
}

inline void pushup(int rt) {
    mx[rt] = max(mx[ls], mx[rs]);
}

void build(int rt, int l, int r) {
    if (l == r) {
        mx[rt] = mp(dep[rdfn[l]], rdfn[l]);
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(rt);
}

void upd(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        --mx[rt].fr;
        --fl[rt];
        return;
    }
    pushdown(rt);
    if (L <= mid) upd(ls, l, mid, L, R);
    if (R > mid) upd(rs, mid + 1, r, L, R);
    pushup(rt);
}

bool vis[N];

int main() {
    int n = rd();
    for (int i = 2; i <= n; ++i) son[fa[i] = rd()].push_back(i);
    dep[1] = 1; dfs(1);
    for (int i = 1; i <= n; ++i) rdfn[dfn[i]] = i; 
    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = mx[1].sc;
        while (p && !vis[p]) {
            ++ans; vis[p] = 1;
            upd(1, 1, n, dfn[p], dfn[p] + sz[p] - 1);
            p = fa[p];
        }
        printf("%d\n", ans);
    }
    return 0;
}