#include <bits/stdc++.h>
using namespace std;  //���������ο�ȫ���У�
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
void dfs(int n) {  // nΪ������ڼ���
	if (n == N + 1) {
		if (isprime(num[1] + num[N])) {  //�Ϸ����
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
			vis[i] = 1;  //���


			dfs(n + 1);  //����һ��
			vis[i] = 0;  //����	
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
                  dfs(2);  //�ӵڶ�����ʼ��
                  cnt++;
                   cout<<"\n";
                   
               
		}

		return 0;
	}

