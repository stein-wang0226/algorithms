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

