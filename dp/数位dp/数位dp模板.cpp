#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n;
const int state = 2;
int b[N];                                   // 每一位
int dp[N][state];                           // dp 数组根据实际情况决定  state  可以对应dfs参数
int dfs(int pos, int state, bool limit) {  //位置(从高位到低位)    状态state
                                            //可多个   limit:是否达到上界_有限制 ：前面每一位都达到上界  （与n的前几位相同）   这样后面每一位都限制上界  不然可以取遍1~9    
  if (pos == 0)   
     if()  return 1;  //   满足条件为1  否则9
     else  return 0;
    //  是上界则则下一位只能到 b[pos]  否则能到9
  if (!limit && ~dp[pos][state]) return dp[pos][state];
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {
    if ()  // 满足某种条件
      ans += dfs(pos - 1, state, limit && i == end);//   is_max每位都为最高位
  }
  if (!limit) dp[pos][state] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}

signed main() {
#ifdef LOCAL

#endif
  cin >> T;
  while (T--) {
  }
  return 0;
}
