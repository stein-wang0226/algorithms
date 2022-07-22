#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
//1~n 所有数中含有49的数字有多少个
// 
const int N = 2e5 + 5;
int T, n, dp[30][2];  //dp[i][0/1]  表示1~i位 的满足不含49个数（无限制（1~i=10^i-1））  第二维表示该位是否位为4
int b[30];// 每一位数字
int dfs(int pos, bool is_4, bool limit) {  //位置(从高位到低位)    状态state     is_4上一位是4(也可直接传数)
                                            //可多个   limit:是否达到上界_有限制 ：前面每一位都达到上界  （与n的前几位相同）   这样后面每一位都限制上界  不然可以取遍1~9    
  if (pos == 0) 
    return 1;  //把0视为一种情况（基数） 最后减去  能到0位的都算一种
  if (!limit && ~dp[pos][is_4]) return dp[pos][is_4]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
    if (!(is_4&&i==9))  // 满足某种条件 （不含49）
      ans += dfs(pos - 1, i==4, limit && i == end);//   is_max每位都为最高位
//如果是*49****  则 算到9****后再
  }
  if (!limit) dp[pos][is_4] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    int k=1;
    int temp=n;
	while(temp)
	{
		b[k++]=temp%10;
		temp/=10;
	}
	k--;
	int ans=n-dfs(k,false,true)+1;// //减去的时候多减了一个0，要把它加上
    cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}


// 正着做  dp[pos][pre][state]为第pos位上，前一个数为pre，目前状态为state（所枚举的这个数字是否含有相邻的49）时的数字数量。
// 要额外考虑之前是否含49
LL dp[25][10][2];
 
int b[25];
 
LL dfs(int pos,int pre,bool state,bool limit)
{
	if(pos==-1)
		return state;
	if(!limit&&dp[pos][pre][state]!=-1)
		return dp[pos][pre][state];
	int up=limit?b[pos]:9;
	LL ans=0;
	for(int i=0;i<=up;i++)
	{
		ans+=dfs(pos-1,i,state||i==9&&pre==4,limit&&i==b[pos]); //或   当前是或之前是都要算上
	}
	if(!limit)
		dp[pos][pre][state]=ans;
	return ans;
}
 
LL solve(LL n)
{
	int cnt=0;
	while(n)
	{
		b[cnt++]=n%10;
		n/=10;
	}
	return dfs(cnt-1,-1,false,true);
}
