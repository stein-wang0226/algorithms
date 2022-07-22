#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
// 这道题的大致意思是给你一个函数F（x）（F(x) = An * 2n-1 + An-1 * 2n-2 + … + A2 * 2 + A1 * 1.）（类似二进制）和两个数a和b。让你去求F(v)<=F(a)(0<=v<=b)之间的个数。
const int N = 2e4 + 5;
int T,  dp[30][N];  ///***巧妙避免初始化   dp值实现重复利用
//  第二位存F(a)-sum   一直做减法 最后判断正负即可  如果存前缀和 每次初始化会超时
//也就是说，如果保存的是前缀和的状态，那么在枚举的时候，就既要保存前缀的状态，又要记录后续的状态。这样就会出现4600*4600的爆炸数组。
//保存sum-sta的状态。这样就可以用一个遍历记录前缀和的状态，然后用这个数组记录后缀的状态，优化空间。
int b[30];// 每一位数字
int Fa;//f(a)的值
int dfs(int pos, int sum,bool limit) {  
                                      
  if (pos == 0){//最后一位跳出 
        if(sum<=Fa)  return 1;  //满足条件
        else return 0;
  }
  if(Fa<sum)return 0 ;// 已经小于 提前结束 
  if (!limit && ~dp[pos][Fa-sum]) return dp[pos][Fa-sum]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
     ans+=dfs(pos-1,sum+i*(1<<(pos-1)),limit&&(end==i));
  }//pos从1开始
  if (!limit)  dp[pos][Fa-sum] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}


int f(int x)
{
    return x == 0 ? 0 : f(x/10)*2+(x%10);
}
void solve(){
    int n,x;
    cin>>x>>n;
    //1~n中满足  f(n)<f(x)  的个数
    Fa=f(x);
    int k=1;
    int temp=n;
    while(temp){
        b[k++]=temp%10;
        temp/=10;
    }
    k--;
    int ans=dfs(k,0,true);
    cout<<ans<<endl;

}
int Case;
signed main() {

  cin>>T;
  Case=0;
  int l,r;
  memset(dp,-1,sizeof dp);
  while (T--) {
    printf("Case #%d: ",++Case);
    solve();
    }
  return 0;
}



