#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, c[N], a, b, sum[N];
void solve() {
	cin >> n >> a >> b;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	ll pre = 0;
	for(int i = 1; i <= n; i++) {
		ans += (c[i] - pre) * b; //先攻下
		//cout << pre << " " << ans << endl;  
        //判断是否需要转移---要转移肯定是攻下后就转移最优  否则对后面点花费肯定更多
		if((c[i] - pre) * a <= (c[i] - pre) * b * (n - i)) {  //转移到该点对后续花费更少
			ans += (c[i] - pre) * a;//转移
			pre = c[i];               // 记录
		}
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}