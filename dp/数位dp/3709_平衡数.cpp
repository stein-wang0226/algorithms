#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
//题意：给出区间 [l,r] 内平衡数的个数，平衡数是指，以某位作为支点，此位左边的 数字*距离 的和与右边相等 
//思路以 dp[pos][x][sta] 代表第pos位的数支点是x，目前力矩为sta的数的个数，对于每一位，以此位为支点计算力矩，然后判断这个数是否为平衡数
//遍历x 判断即可
const int N = 2e5 + 5;

int T, n, dp[30][30][3000]; 
// dp[pos][x][sta] 表示 第(后)pos位数 支点是x 
int b[30];// 每一位数字
int dfs(int pos,int  x, int state,bool limit) {  //位置(从高位到低位)  支点  力矩   限制 
                                            //可多个   limit:是否达到上界_有限制 ：前面每一位都达到上界  （与n的前几位相同）   这样后面每一位都限制上界  不然可以取遍1~9    
  if (pos == 0){//最后一位跳出 
        if(state==0)  return 1;  //满足条件  力矩为0
        else return 0;
  }
  if(state<0)  //剪枝 力矩小于0则不用继续 （左正用负） 平衡则最后到0 不会为负
     return 0; //
  if (!limit && ~dp[pos][x][state]) return dp[pos][x][state]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
        int temp=state+i*(pos-x);
        ans+=dfs(pos-1,x,temp,limit&&(end==i));    
  }
  if (!limit)  dp[pos][x][state] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}
int cal(int n){
    int k=1;
    int temp=n;
    //太大可以读字符串
	while(temp)
	{
		b[k++]=temp%10;
		temp/=10;
	}
	k--;
    int sum=0;
	for(int i=1;i<=k;i++){ //枚举支点
        sum+=dfs(k,i,0,true);
    }
    return sum-(k-1); //减去  00 000 0000...的情况
}


signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>T;

  while (T--) {
    memset(dp,-1,sizeof dp);
    int l,r;
    cin>>l>>r;
    int ans=cal(r)-cal(l-1);
    cout<<ans<<endl;
    }
  return 0;
}

