#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
using uint64 = unsigned long long;
const int N = 36666670;
const int S = 255; // 11111111
uint64 T, n, seed;
int val[300][300]; //预处理
int cnt[300][8]; //64位分8段 cnt[i][j] :第j段的8位二进制数i的总出现次数
// 统计每一位1的个数
// 只有0xor1会产生贡献  每位0 1 个数相乘 累加即可
void solve() {
	cin >> n >> seed;
	std::mt19937_64 mt_rand(seed);

	for (int i = 1; i <= n; i++) {  //直接读入  存不下
		uint64 t = mt_rand(), v;
		for (int j = 0; j < 8; j++) {
			v = t & S; //末8位
			cnt[v][j]++; // 记录权值出现次数
			t >>= 8;
		}
	}

//每段分别求和
	int ans = 0;
	for (int i = 0; i <=S; i++) { //枚举一大一小两个8位二进制数（预处理过）
		for (int j = i + 1; j <= S; j++) {
			uint64 x = val[i][j], res = 0; //
			for (int k = 0; k < 8; k++) { //8段分别求和
				res += cnt[i][k] * cnt[j][k]; // 出现次数的乘积（对数）*val（1的个数）就是答案
			}
			ans += res * x;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

//预处理8位所有数的两两异或值 二进制的1个数
	for (int i = 0; i <= S; i++) {
		for (int j = i + 1; j <= S; j++) {
			val[i][j] = __builtin_popcount(i ^ j);
		}
	}
	solve();

	return 0;
}
