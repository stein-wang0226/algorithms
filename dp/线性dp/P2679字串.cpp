#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;
// P2679  现在要从字符串 A 中取出 k 个互不重叠的非空子串，然后把这 k
// 个子串按照其在字符串 AA
// 中出现的顺序依次连接起来得到一个新的字符串。请问有多少种方案可以使得这个新串与字符串
// B相等？ 类似于 hello world 多一维k 如果和不能和前一个字符接上则+1 dp[i][j][k]
// 表示从字符串 A 中前 i 个字母组成的字符串中选出 k 个互不重叠的子串 组成字符串 B
// 中前 j 个字符表示的字符串有多少种方法。 如果 A 第 ii 个字符与 B 的第 j
//个字符并不相同，那么显然 dp[i][j][k]=dp[i-1][j][k] 如果ai = bj  但ai-1!=b
//j-1(隔开) 那么f[i][j][k]=f[i−1][j][k]+f[i−1][j−1][k−1]//接上j-1
//且字串数不变，被隔开ai-1!=b j-1(隔开)
//*****当ai及前t位都与bj前t位相等时f[i][j][k]=f[i−1][j][k]+f[i−1][j−1][k−1]⋯+f[i−1][j−t][k−t](求前缀和)
//要点 如上若最后t位连续与b相等，t位可分为1~t段 ：如果当前位匹配上了 我们可以接着第k次配对，或者是找到之前的第k−i次的串配对....。
//f[i][j][k]=(f[i−1][j][k]+f[i−1][j−1][k])+  前一个 sum:  f[i−1][j−1][k−1]⋯+f[i−1][j−t][k−t]
const int mod= 1000000007 ;//用sum数组维护f[i−1][j−1][k−1]⋯+f[i−1][j−t][k−t]，dp只需加上dp[i-1][j][k]          
char a[1005], b[205];
int dp[2][205][205];
int sum[2][205][205];
	int n, m, t;
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
 const int mod = 1000000007, N = 1005;
	cin>>n>>m>>t;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	dp[0][0][0] = dp[1][0][0] = 1;
	int now = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= t; k++) {
				dp[now][j][k] = (dp[now ^ 1][j][k]) % mod;//
				if(a[i] == b[j]) {
					sum[now][j][k] = ( sum[now ^ 1][j - 1][k] + dp[now ^ 1][j - 1][k - 1]) % mod;
				} else {
					sum[now][j][k] = 0;//不相等则中断
				}
				dp[now][j][k] = (dp[now][j][k] + sum[now][j][k]) % mod;//
			} 
		}
		memset(sum[now ^ 1], 0, sizeof(sum[now ^ 1]));
		now ^= 1;//取反
	}
	cout << dp[now ^ 1][m][t] << endl;
	return 0;
}

