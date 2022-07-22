#include <bits/stdc++.h>
#define LOCAL
using namespace std;  //素数环（参考全排列）
int N, flag, num[1000], vis[1000];
int isprime(int m) {
	if (m == 1) return 0;
	for (int i = 2; i < m; i++) {
		if (!(m % i)) {
			return 0;
		}
	}
	return 1;
}
void dfs(int n) {  // n为正在填第几个
	if (n == N + 1) {
		if (isprime(num[1] + num[N])) {  //合法输出
		flag=1;
		cout<<num[1];
			for (int i = 2; i <= N; i++) cout << " "<<num[i];
			cout << "\n";
		}
		return ;
	}

	for (int i = 2; i <= N; i++) {
		if (isprime(i + num[n - 1]) && !(vis[i])) {
			num[n] = i;
			vis[i] = 1;  //标记

			dfs(n + 1);  //填下一个
			vis[i] = 0;  //回溯	
			}
		}
	}
	int main() {
#ifdef LOCAL
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
#endif
                int cnt = 1;
                while (cin >> N) {
                  memset(vis, 0, sizeof vis);
                  memset(num, 0, sizeof num);
                  vis[1] = 1;
                  num[1] = 1;
                  flag = 0;
                  printf("Case %d:\n", cnt);
                  dfs(2);  //从第二个开始填
                  cnt++;
                   cout<<"\n";
                   
               
		}

		return 0;
	}
