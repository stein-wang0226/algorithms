# 数位dp

## 原理

利用记忆化搜索，从高位到低位，满足条件跳出返回1，否则返回0

用limit参数控制上界  只有没有限制的状态才转移

dp[ pos] [state]  记录 ，转移 pos 为搜到的位数（从大到小），state 储存状态 可多维

------



## 模板

```C++
#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[N];                                   // 每一位
int dp[N][state];                           // dp 数组根据实际情况决定  state  可以对应dfs参数
int dfs(int pos, int state, bool limit) {  //位置(从高位到低位)    状态state
                                            //可多个   limit:是否达到上界_有限制 ：前面每一位都达到上界  （与n的前    												相同）   这样后面每一位都限制上界  不然可以取遍1~9    
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
  
```

------



## 例题

### 1.模板题：1~n 中含49 的数的个数

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
//1~n 所有数中含有49的数字有多少个
//  到着做  算不含的
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

//正着做 需要多一维state ：因为只要前面有49出现就会向后传递


//   dp[pos][pre][state]为第pos位上，前一个数为pre，目前状态为state（所枚举的这个数字是否含有相邻的49）时的数字数量。
//需要多一维state ：因为只要前面有49出现就会向后传递
// 要额外考虑之前是否含49
LL dp[25][10][2];
int b[25];
LL dfs(int pos,int pre,bool state,bool limit)
{
	if(pos==-1)
		return state==1;  //满足条件返回1
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


```



### 2.模板题2 ：两个条件

hdu3652

题意：求<=n，满足包含13且能被13整除的数的个数 

```C++
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
      //同时满足两个跳出条件
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



```



### 3.三个条件

题意：[l,r]  
//　　如果一个整数符合下面3个条件之一，那么我们就说这个整数和7有关——
// 　　1、整数中某一位是7；
// 　　2、整数的每一位加起来的和是7的整数倍；
// 　　3、这个整数是7的整数倍；
// 　　现在问题来了：吉哥想知道在一定区间内和7无关的数字的平方和

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
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
```



### 4.hdu3709求平衡数

遍历每位支点，从高位到低位 判断是否满足即可

```C++
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


```



### 5.数字字符串匹配趋势的个数

长度100，字符串处理

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"    
using namespace std;
// A,B之间有多少个数，满足给定字符串的趋势  /\  -->增减

const int N = 2e5 + 5;

const int MOD=100000000;
string s; //模式串
int T, n, dp[105][105][10];
int b[110]; //
// /***   dp[pos][j][pre]    匹配到第pos位  之前最多匹配了模式串的cnt位 上一位是pre的数量
string erase0(string s){
    string res;
    int flag=1; //是0
    for(int i=0;i<s.size();i++){
        if(flag&&s[i]=='0'){
            continue;
        }
        flag=0;
        res.push_back(s[i]);
    }
    return res;
}

string sub1(string a){ //字符串减1

    int len=a.size();
    if(a[len-1]>'0'){
        a[len-1]-=1;
        return a;
    }
    else{
        int i=len-1;
        while(i>=0&&a[i]<='0')
            a[i--]='9';
        a[i]-=1;
        return a;
    }
}
int check(int x,int y,char op){// 判断x,y 是否匹配
    if(op=='/')return x<y;
    if(op=='-')return x==y;
    return x>y;
}

int dfs(int pos,int  cnt, int pre,bool is_0,bool limit) {  //位置(从高位到低位)  匹配数  上一位 是否前导0   限制 

  if (pos == 0){//最后一位跳出 
        if(cnt==s.size())  return 1;  //满足条件 模式串全部匹配
        else return 0;
  }

  if (!limit && ~dp[pos][cnt][pre]) return dp[pos][cnt][pre]; //  没有限制才转移（1~9）
  int end = limit ? b[pos] : 9;  //该位最大值
  int ans = 0;
  for (int i = 0; i <= end; i++) {//枚举pos-1位(下一位)
        if(is_0){
            ans+=dfs(pos-1,0,i,is_0&&(i==0),limit&&(i==end)); //等价于后移一位
        }
        else{
            //两种情况可以继续匹配
            if(cnt<s.size()&&check(pre,i,s[cnt])) // 满足下一个当前两个数字满足下一个模式串就向后  向下一个匹配(从0开始)
                ans+=dfs(pos-1,cnt+1,i,0,limit&&(i==end)); //向后
            else if(cnt>0&&check(pre,i,s[cnt-1])) //能继续
                ans+=dfs(pos-1,cnt,i,0,limit&&(i==end)); //继续匹配当前字符
        }
  }  ans%=MOD;

  if (!limit)  dp[pos][cnt][pre] = ans;  //没有限制才转移（1~9）  不然无法准确判断
  return ans;
}

int cal(string x){
    memset(dp,-1,sizeof dp);
    int len=x.size();
    for(int i=0;i<len;i++){
        b[len-i]=x[i]-'0';    //高位到低位 
    }
    return dfs(len,0,0,1,1);
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

    string s1,s2;
  while (cin>>s) {
    memset(dp,-1,sizeof dp);
    cin>>s1>>s2;
    s1=erase0(s1);
    s2=erase0(sub1(s2));

    int ans=(cal(s2)-cal(s1)+MOD)%MOD;
    printf("%08ld\n",ans);
    }
  return 0;
}


```

