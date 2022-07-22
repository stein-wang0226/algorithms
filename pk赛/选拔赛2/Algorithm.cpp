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

#define N 2000007
#define pb push_back

ll ans;

int a[N], fa[N], f[N];

vector<int> son[N];

void dfs(int u) {
	ll sum = 0;
	for (auto v : son[u]) {
		dfs(v);
		sum += f[v];
		f[u] = max(f[u], f[v]);
	}
	ans += sum - f[u];
	f[u] = max(f[u], a[u]); 
}

int main() {
	int n = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	for (int i = 1; i <= n; ++i) son[fa[i] = rd()].pb(i);
	for (int i = 1; i <= n; ++i)
		if (fa[i] == 0) {dfs(i); ans += f[i];}
	printf("%lld\n", ans);
	return 0;
}