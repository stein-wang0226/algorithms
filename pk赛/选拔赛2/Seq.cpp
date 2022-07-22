#include <bits/stdc++.h>
#define N 100007
#define mod 1000000007
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

int n, q, a[N], b[N];

inline void work() {
	int k = rd();
	int tot = 0;
	for (int i = 1; i * i <= k; ++i) 
		if (k % i == 0) {
			b[++tot] = i;
			if (k / i != i) b[++tot] = k / i;
		}
	sort(b + 1, b + 1 + tot);
	int ans = 1, ptr = 1;
	for (int i = 1; i <= n; ++i) {
		while (ptr < tot && a[i] >= b[ptr + 1]) ++ptr;
		ans = 1ll * ans * ptr % mod;
	}
	printf("%d\n", ans);
}

int main() {
	n = rd(); q = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	sort(a + 1, a + 1 + n);
	while (q--) work();
	return 0;
}