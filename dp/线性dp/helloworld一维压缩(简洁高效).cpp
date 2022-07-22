#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;//hello world -- 线性二维dp(求一串字符中所有hello world的个数)
int t;
const int MAX=1e5+5;
const int mod = 998244353;
int dp[11];
char s[MAX];
int main()//  dp i,j 方式 考虑到第 i 个字符，已经匹配了 j 个
          //字符的方案数。初始状态下仅有 dp 0,0 =1 ，其余均为 0 
{         //记给定的待匹配串为 s ，目标序列"helloworld"为 t ，则如果 si=tj ，有 dpi,j=dpi−1,j + dpi−1,j−1 ，否则 dpi,j=dpi−1,j 。
#ifdef LOCAL//由于每个状态我们仅在一次转移中用到，我们可以对数组进行压缩***，其空间复杂度可以被优化到 O(10) 维
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
  while(t--){
    cin>>s;
    int n=strlen(s);
    memset(dp,0,sizeof dp);
    dp[0]=1;
   for (int i = 0; i < n; ++i) {
		switch (s[i]) {//
			case 'h':
				dp[1] += dp[0];
				dp[1] %= mod;
				break;
			case 'e':
				dp[2] += dp[1];
				dp[2] %= mod;
				break;
			case 'l':
				dp[9] += dp[8];
				dp[9] %= mod;
				dp[4] += dp[3];
				dp[4] %= mod;
				dp[3] += dp[2];
				dp[3] %= mod;
				break;
			case 'o':
				dp[7] += dp[6];
				dp[7] %= mod;
				dp[5] += dp[4];
				dp[5] %= mod;
				break;
			case 'w':
				dp[6] += dp[5];
				dp[6] %= mod;
				break;
			case 'r':
				dp[8] += dp[7];
				dp[8] %= mod;
				break;
			case 'd':
				dp[10] += dp[9];
				dp[10] %= mod;
				break;
		}
	}
	printf("%lld\n", dp[10] % mod);
}
    return 0;
}
