#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
//题意：[l,r]  
//　　如果一个整数符合下面3个条件之一，那么我们就说这个整数和7有关——
// 　　1、整数中某一位是7；
// 　　2、整数的每一位加起来的和是7的整数倍；
// 　　3、这个整数是7的整数倍；
// 　　现在问题来了：吉哥想知道在一定区间内和7无关的数字的平方和。
//倒着  算满足的
const int N = 2e5 + 5;
int T, n, dp[30][10][10][2]; // dp[pos][mod1][mod2][state][2]  位置(从高位到低位)  到该位每一位求和对7取模   之前组成的数模  到该位是否含7 
int b[30];// 每一位数字
int dfs(int pos, int mod1,int mod2, bool state,bool limit) {  //位置(从高位到低位)  到该位每一位求和对7取模   之前组成的数模  到该位是否含7  限制 
                                      
  if (pos == 0){//最后一位跳出 
        if(state||mod1==0||mod2==0)  return 1;  //满足条件
        else return 0;
  }
  if (!limit && ~dp[pos][mod1][mod2][state]) return dp[pos][mod1][mod2][state]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
      ans += dfs(pos - 1,(mod1+i)%7, (mod2*10+i)%7,state||(i==7),limit && (i == end));//   is_max每位都为最高位
//如果是*49****  则 算到9****后再
  }
  if (!limit)  dp[pos][mod1][mod2][state] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}
int cal(int n){
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
	return dfs(k,0,0,false,true);// //减去的时候多减了一个0，要把它加上
}



signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>T;
  int l,r;
  while (T--) {
    cin>>l>>r;
    int ans=cal(r)-cal(l-1);
    //ans=(r-l+1)-ans;
    cout<<ans<<endl;  
    }
  return 0;
}



