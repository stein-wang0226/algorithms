#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
//题意：求<=n，满足包含13且能被13整除的数的个数// 
const int N = 2e5 + 5;
int T, n, dp[30][15][10][2]; 
int b[30];// 每一位数字
int dfs(int pos, int mod,int pre, bool state,bool limit) {  //位置(从高位到低位)  从0到该位模13结果   上一位   到该位是否含13   限制 
                                            //可多个   limit:是否达到上界_有限制 ：前面每一位都达到上界  （与n的前几位相同）   这样后面每一位都限制上界  不然可以取遍1~9    
  if (pos == 0){//最后一位跳出 
        if(state&&mod==0)  return 1;  //满足条件
        else return 0;
  }
  if (!limit && ~dp[pos][mod][pre][state]) return dp[pos][mod][pre][state]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
      ans += dfs(pos - 1, (mod*10+i)%13, i,state||(pre==1&&i==3),limit && i == end);//   is_max每位都为最高位
//如果是*49****  则 算到9****后再
  }
  if (!limit)  dp[pos][mod][pre][state] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin>>n) {
    memset(dp,-1,sizeof dp);
    int k=1;
    int temp=n;
    //太大可以读字符串
	while(temp)
	{
		b[k++]=temp%10;
		temp/=10;
	}
	k--;
	int ans=dfs(k,0,0,false,true);// //减去的时候多减了一个0，要把它加上
    cout<<ans<<endl;  }
  return 0;
}


