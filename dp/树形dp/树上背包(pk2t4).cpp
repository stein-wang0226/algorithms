#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
const int N = 2e4 + 5;
const int M = 1e3+5;
int T, n, k, q, a[N];
int head[N], tot;
int dp[N][N];// dp[i][j]从 i出发 ，向下走j趟的最多点数
struct Edge {
	int to, next;
} edge[N * 2];
void add(int u, int v) {
	edge[++tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot;
}

int dfs(int u) {
	int sz = 1;
	for (int i=head[u];~i;i=edge[i].next) {
		int v=edge[i].to;
		int szs = dfs(v);
		sz += szs;
		for (int j = sz; j >= 1; --j)
			for (int k = 1; k <= szs; ++k)
				if (j >= k) dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
	}
	for (int i = 1; i <= sz; ++i) ++dp[u][i];
	return sz;
}

void solve() {
	memset(head, -1, sizeof head);
	memset(dp,0,sizeof dp);
	tot = 0;
	cin >> n;
	int u;
	for (int i = 2; i <= n; i++) {
		cin >> u;
		add(u, i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<dp[1][i]<<endl;
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	solve();

	return 0;
}
