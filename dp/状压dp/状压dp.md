# 状压dp

## 实质：将有限状态数用二进制数表示

## 1.常用的二进制计算方法

一、取出x的第i位：y = ( x>> ( i-1 ) ) & 1

二、将x的第i位取反：x = x ^ ( 1<< ( i-1 ) )

三、将x的第i位变为1： x = x | ( 1<< ( i-1 ) )

四、将x的第i位变成0： x = x & ~（ 1<< ( i-1 ) ）

五、将x最靠右的1变成0： x = x & (x-1)

六、取出最靠右的1 ：y=x&(-x)

七、把最靠右的0变成1: x | = (x-1)

------



## 2.例题

### 	例1、关灯问题

这道题目是一个状压的引入和理解，没有涉及dp。

[关灯问题]:https://www.luogu.com.cn/problem/P2622

![image-20240818142413549](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20240818142413549.png)

#### 分析：

 考虑状态压缩，可以把灯的开和关视作1和0，则用一串01串（二进制）表示这一串灯的一个总的状态。

因为这个01串是而进制，所以他们所对应的10进制数最大不会超过（2<<10）-1=1023
也就是说最多有1023种状态，所以当然是可行的。

那么这题就可以直接广搜暴力(每按一次相当于走一步)解决，利用之前的计算方法，开灯（1）就是把对应的那一位0变成1： x|=1<<(i-1),如果本身是1的话当然没有任何影响。
同理，关灯（-1）的话就是把对应的那一位1变成0： x=x&~(1<<(i-1)),当然如果本身是0 ，也没有影响啦。



#### 代码

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//10维数组  用一个长度为10 的二进制数表示10个开关 （一位dp数组）
// bfs求最短路即可
int dp[2000];// 存答案
const int N = 2e3 + 5;
int T, n,m, a[N][N]; // a[i][j]表示第i个开关对第j个灯的效果
int vis[N];
void solve(){
    
cin>>n>>m;
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        cin>>a[i][j];
    }
}
memset(dp,-1,sizeof dp);dp[(1<<n)-1]=0; //初始化
queue<int>que;
int flag=0; //是否找到
que.push((1<<n)-1); //开始全亮的状态
vis[(1<<n)-1]=1;
while (!que.empty()){ //广搜
    int u=que.front();
    que.pop();
    for(int i=1;i<=m;i++){ //每个开关尝试
        int state=u;
        for(int j=1;j<=n;j++){
            if(a[i][j]==0)continue;//不变
            else if(a[i][j]==1)  state=state&~(1<<(j-1)); //第j位为1  关
            else if(a[i][j]==-1)  state|=(1<<(j-1)); //开
        }

        if(!vis[state]){
            vis[state]=1;
            que.push(state);
            dp[state]=dp[u]+1;
            if(state==0){
                flag=1;
                break;
            }
        }
    }
    if(flag)break;
}
    if(flag) cout<<dp[0]<<endl;
    else cout<<-1<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}

```

------



### 例2.  hdu 3182 Hamburger Magi

[Hamburger Magi]:http://acm.hdu.edu.cn/webcontest/contest_showproblem.php?pid=1000&ojid=0&cid=14300&hide=0



##### 题意：

题目大意:给我们一些物品,有价值和大小,要求一定容量内放进物品价值最大,教练 这个我熟,01背包~但是这道题的每个物品有一个限制条件,就是有些物品有一些前置物品,必须在那些物品都放进去之后它才能放进去,建图dfs?不太好,正解是压缩状态dp,比较好想的思路就是把所有状态找出来（01表示选与不选）,然后遍历所有状态判断是否其中所有点的前置点是否都在其中,不满足就不考虑这个状态,但是这样暴力会超时... 正解是初始化所有放置情况为-1,即都不满足要求,dp[0]=0,就0满足,然后遍历所有状态,在每种状态下对其中的物品进行选择更新,如果用于更新的状态==0,就直接跳过,全部满足再向后更新，时间大大减少.

#### 代码

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e2 + 5;
int T, n,E, a[N];
int e[20]; //
int v[20]; //value
int dp[1<<20]; //
int need[20]; //每个物品的限制---二进制
int energy[N];//  状态下剩余能量
bool check(int state,int x){//能否将x加入  及判断x的限制条件是否完全包含于sta
    if((need[x]|state)==state)return 1;
    else return 0;
}
void solve(){
    cin>>n>>E;
        //memset(e,0,sizeof e);
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>e[i];
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        int sta=0;
        while(num--){
            int x;cin>>x;
            sta|=(1<<(x-1));
        }
        need[i]=sta;  //限制条件的二进制
    }
    memset(dp,-1,sizeof dp);//初始化为不可能
    dp[0]=0;//
    energy[0]=E;//
    int ans=0;
    for(int i=0;i<=(1<<n)-1;i++){//状态
        if(dp[i]>=0)//该状态满足  
            for(int j=1;j<=n;j++){//用该状态更新其他状态   判断能否添加
                if(!(i&(1<<(j-1)))&&check(i,j)){  //i中不含j但j可加入
                if(energy[i]<e[j])continue;  //太贵
                    int sta=i|(1<<(j-1));
                    dp[sta]=dp[i]+v[j]; //更新
                    ans=max(ans,dp[sta]);
                    energy[sta]=energy[i]-e[j]; //剩余
                }
            }
    }
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

```

### 例3. hdu 5691 Sitting in Line***

//和例6旅行商问题状态表示方式相同 详见例6

#### tsp 问题：np 完全问题  二维

[Sitting in Line]:http://acm.hdu.edu.cn/webcontest/contest_showproblem.php?pid=1001&ojid=0&cid=14300&hide=0

#### 题面：

度度熊是他同时代中最伟大的数学家，一切数字都要听命于他。现在，又到了度度熊和他的数字仆人们玩排排坐游戏的时候了。游戏的规则十分简单，参与游戏的N个整数将会做成一排，他们将通过不断交换自己的位置，最终达到所有相邻两数乘积的和最大的目的，参与游戏的数字有整数也有负数。度度熊为了在他的数字仆人面前展现他的权威，他规定某些数字只能在坐固定的位置上，没有被度度熊限制的数字则可以自由地交换位置。

#### 思路：

##### 状态表示：考虑每次插入一个数,但答案与插入顺序无关，所以考虑每次插入到末尾的最大方案也即答案

首先我们假设dp[1<<16] [16],第一维可以表示成一个16位二进制数,其中,二进制数的第i位如果为1表示a[i]已经选择好放的位置,否则即a[i]还没有选定位置;dp数组第二维表示该目前以a[j]结尾的序列, max{a1*a2+a2*a3+...}  

##### 状态转移：

枚举状态i，结尾数字j，未填数字k：如果当前位置必填某个数,那么,就只更新以规定的这个数结尾转移方程如果没有那就枚举那么可以任意放的数来更新相应的状态及答案

dp[i|(1<<k)] =max(dp[i] [(1<<k)] [k],dp[i] [j]+a[j]*a[k]);

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int inf=0x3f3f3f3f;
const int N = 25;
int T, n, a[N],pos[N];
int dp[1<<20][20];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>pos[i];
    }
	for(int i=0;i<(1<<N);i++){
		for(int j=1;j<=n;j++){
            dp[i][j]=-inf; //初始化-inf  因为刚开始有0
        }
    }
    for(int i=0;i<N;++i)  
            if(pos[i]==0||pos[i]==-1)  //***
            dp[1<<i][i]=0;  
		//dp
   for(int i=0;i<(1<<N);++i)  
            for(int j=0;j<N;++j)  
                if(dp[i][j]!=-INF)  
                    for(int k=0;k<N;k++)  
                        if( (i&(1<<k))==0&&(pos[k]==-1||pos[k]==__builtin_popcount(i)))   //能插到末尾 最后一个条件很巧妙 保证是最后一位且连续c
                                dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+a[j]*a[k]);// 转移  结尾  
        int mmax=-INF;  
        for(int i=0; i<N; ++i)  
            mmax=max(mmax,dp[(1<<N)-1][i]);  
        cout<<"Case #"<<(++cas)<<":"<<endl<<mmax<<endl; 
	

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

```





### 例4. acw 1064小国王, （棋盘问题）

#### 题意：

在 n×n 的棋盘上放 k 个国王，国王可攻击相邻的 8 个格子，求使它们无法互相攻击的方案总数。

#### 思路：

按行枚举每列放与不放01，下一行的方案取决于上一行 dp[i] [j] [s] 表示摆了前i行，已放j个国王，第i行状态为s的方案数

#### 最坏复杂度：（实际小非常多）

状态数*转移数

#### 转移的情况：

每行内不能有1相邻  --->  

第i行和第i-1行不能相互攻击 --->a&b==0 && （a|b）不能有相邻1

#### 做法：

先预处理出一行的所有合法状态和每个合法状态能转移到的合法状态，再一行一行枚举所有合法状态dp

tip：可滚动一维

#### 代码

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N=12;//棋盘
const int M=1<<11,K=110; //状态数和国王数
int T, n,k, a[N];

vector<int>state; //所有合法状态***
vector<int>tran[M]; //状态s  能转移到的所有合法状态  9预处理）
int  dp[N][K][M];   //表示摆了前i行，已放j个国王，第i行状态为s的方案数
int cnt[M]; //每个状态1的个数

bool check(int state) //判断没有相邻1
{
    return  !(state & state << 1);
}


void solve(){
    cin>>n>>k;
    //先预处理
    for(int i=0;i<=(1<<n)-1;i++){
        if(check(i)){
                state.push_back(i);
                cnt[i]=__builtin_popcount(i);  //顺便求二进制1的个数
            }    
    }
    //  处理tran数组
    for(int i=0;i<state.size();i++){  //其实空间够 没必要用下标处理  见下一题
        int a=state[i];
        for(int j=0;j<state.size();j++){
            int b=state[j];
            if((a&b)==0&&check(a|b))
                tran[i].push_back(j); //注意是下标
        }
    }
//dp
dp[0][0][0]=1; // 初始化  啥也不摆算一种

for(int i=1;i<=n+1;i++){
    for(int j=0;j<=k;j++){//放的国王数
        for(int s=0;s<state.size();s++){//合法状态下标
            for(int b:tran[s]){//s  能到达的状态

                int count=cnt[state[s]];//a中一的个数
                if(count<=j){//满足数量
                    dp[i][j][s]+=dp[i-1][j-count][b]; //转移
                }
            }
        }   
    }
}

// 技巧  ：答案总数转化为  摆到第n+1 行 改行一个没摆的方法数  减少计算
int ans=dp[n+1][k][0];
cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}

```

### 例5. acw 327玉米田

#### 题意：

农夫约翰的土地由 M×N个小方格组成，现在他要在土地里种植玉米。

非常遗憾，部分土地是不育的，无法种植。

而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。

现在给定土地的大小，请你求出共有多少种种植方法。

土地上什么都不种也算一种方法。

#### 思路

和上一题类似 没有个数限制

dp[i] [j]  表示已经摆完前i行，且该行状态是s的集合

不相邻：1.每行无连续1   2.对相邻状态a，b：（a&b）==0;

 再用位运算判断是否能摆（输入中1的位置不能对应0，考虑将输入的二进制取反与状态&判断是否全0，不是0就不合法  （if（~a&b==0）））

```C++
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 20 ;
const int M=1<<12,mod=1e8;

int T,m, n, a[N];
int g[N]; //每一行的初始状态（取反后）
vector<int>state; //合法状态
vector<int>trans[M]; //i可转移到的合法状态
int dp[N][M];
bool check(int state) //判相邻
{
    return  !(state & state << 1);
}

void solve(){
    cin>>n>>m;
    int t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t;
            g[i]|=!t<<(j-1);   //等价于取反后
        }
    }
//预处理合法状态
    for(int i=0;i<=(1<<m)-1;i++){
        if(check(i))state.push_back(i);
    }
//预处理合法状态的合法转移
    for(auto i:state)
        for(auto j:state)
            if(!(j&i))
            trans[i].push_back(j);
    
    dp[0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(auto j:state){
            if(!(j&g[i]))  //合法可以放
                for(auto k:trans[j])
                    dp[i][j]+=dp[i-1][k]%mod,dp[i][j]%=mod;
        }
    }
    //滚动一维
    // f[0][0] = 1;
    // for (int i = 1; i <= n + 1; ++ i)
    //     for (auto st: state)
    //     {
    //         f[i & 1][st] = 0;
    //         if (!(st & g[i]))
    //             for (auto pre_st: head[st])
    //                 f[i & 1][st] = (f[i & 1][st] + f[(i - 1) & 1][pre_st]) % mod;
    //     }
    // cout << f[(n + 1) & 1][0] << endl;
	int ans=dp[n+1][0];  //上一题同款操作
	cout<<ans<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
      solve();
  return 0;
}

```



### 例6.HDU - 5418 Victor and World （TSP问题求最小哈密顿回路 floyd + 状压dp）

旅行商问题：求最小哈密尔顿路径：（要返回起点）（最后加上到起点的边即可）

#### 题意：无向图中有 n 个点 m 条边，求最小[哈密顿回路](https://so.csdn.net/so/search?q=哈密顿回路&spm=1001.2101.3001.7020)的长度。（基本回路）

####  时间复杂度分析

原先 O(n!)   -->2^n*n;

#### 思路：

先Floyd预处理出两点最短路

##### 状态表示：

dp[i] [j]   i表示所有点选择状态      表示最后一个点是j  dp[i] [j] 表示该状态下的 最小值

##### 状态转移：

遍历i j  满足 i&(1<<j) 枚举点k作为j的前一个点dp[i] [j]=min(dp[i] [j],dp [i-(1<<j)] [k]+w [k] [j])

为什么是对的：  已经得到之前状态的最优解 ，那么我们只要考虑最后一步，类似前两题的表示

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const int N = 17 ;
int T, n,m, a[N];
int dis[N][N],dp[1<<N][N];
void solve(){
    cin>>n>>m;
    memset(dp,0x3f,sizeof dp);
    memset(dis,0x3f,sizeof dis);
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    
		for(int i=1;i<=n;i++)dis[i][i]=0;
    //floyd
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

dp[1][1]=0; //从1出发

for(int i=0;i<(1<<n);i++){
    for(int j=1;j<=n;j++){
        if(i&(1<<(j-1))) // i 中已经过第j个  可以转移
        for(int k=1;k<=n;k++){
            if(i&(1<<(k-1)))  // 枚举j前一个走过的点k
                dp[i][j]=min(dp[i][j],dp[i^(1<<j-1)][k]+dis[k][j]);
        //	if(i&(1<<k-1))continue;
		// 	dp[i|(1<<(k-1))][k]=min(dp[i|(1<<k-1)][k],dp[i][j]+dis[j][k]);
         }
    }
}
    //这里要求回到1 所以对每个终点+ dis[i][1]取max
	long long ans=1e9+7;
		for(int i=1;i<=n;i++)ans=min(ans,dp[(1<<n)-1][i]+dis[i][1]);
		cout<<ans<<endl;
//若求最小哈密尔顿  则  ans= d[1<<n-1][n]  	

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

```

### acwing91最短Hamilton路径

```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long 

using namespace std;
const int N = 20;
int dis[N][N],dp[1<<N][N]; // 索引只能从0开始   卡空间
// dp[s][j]  到达状态为s 末节点为j 的最短距离
// 转移: dp[s][j] = min(dp[t][k],..)  t is s minus a 0 , k is the existed 1 in s
int n;
signed main(){
    cin>>n;
    // input adjacency matrix 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dis[i][j];
        }
    }
    
    memset(dp,0x3f,sizeof dp); // 初始化 inf
    dp[1][0]=0; // 起点为0
    for(int s=0;s<(1<<n);s++){
         if (!(s & 1))continue; // 优化  起点为1
        for(int j=0;j<n;j++){
            if(s&(1<<j)){ // s中已包含j
                for(int k=0;k<n;k++){ 
                    if((s&(1<<k))&&k!=j){// 同理包含k
                        int t = s ^(1<<j); // s 去掉j
                        // if(dp[t][k]+dis[k][j]<dp[s][j])cout<<"update"<<" "<<j<<endl;
                        dp[s][j] = min(dp[s][j], dp[t][k]+dis[k][j]);
                    }
                }
            }
                
        }
    }
    
        // for(int i=1;i<=n;i++)cout<<dp[(1<<n)-1][i]<<" ";
        cout<<dp[(1<<n)-1][n-1]<<endl;
    
    
    
    return 0;
}
```



### 例7.方格取数：棋盘问题

#### 题意：

给你一个n*n的格子的棋盘，每个格子里面有一个非负数。
从中取出若干个数，使得任意的两个数所在的格子没有公共边，就是说所取的数所在的2个格子不能相邻，并且取出的数的和最大。

#### 思路：

同例4、5，按行枚举状态，前后不能相邻,

先预处理出一行的所有合法状态和每个合法状态能转移到的合法状态，再一行一行枚举所有合法状态dp(与例4一样，只不过例4是方案数)

##### 状态表示：

dp[i] [s] 表示前i行 ，第i行状态为s的最大和

##### 状态转移：

先初始化为上一行dp[i] [k]=dp[i-1 ] [j]

对每一给要选的格子

dp[i] [k] += w[ i] [pos]

//下次别用vector  卡空间

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 21;
const int M=1<<N;
int T, n, w[N];
int dp[N][M]; // 表示前i行 ，第i行状态为s的最大和
vector<int>state;
vector<int>trans[M];
bool check(int state){//判相邻
    return !(state&state<<1);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>w[i][j];
            
//dp
 memset(dp,0,sizeof dp);
 dp[0][0]=0;
 int ans=0;
 for(int i=1;i<=n;i++){  //行
     for(auto j:state){//合法状态
         for(auto k:trans[j]){  //可转移上一行合法状态
             dp[i][j]=dp[i-1][k];
             for(int pos=1;pos<=n;pos++){
				if(k&1<<(pos-1))dp[i][j]+=w[i][pos]; //按状态计算
             }
         }
          if(i==n)ans=max(ans,dp[i][k]);
     }
 }

    
cout<<ans<<endl;


}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//预处理合法状态
    for(int i=0;i<=(1<<20)-1;i++){
        if(check(i))state.push_back(i);
    }
//预处理合法状态的合法转移
    for(auto i:state)
        for(auto j:state)
            if(!(j&i))   //两行不相邻
            trans[i].push_back(j);
    
  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}

```

### 例7.Campus Design HDU - 4804 （状压dp，轮廓线dp）（待补）



### 例8.hdu5555（待补）

#### 题意：

给你一个NxN的网格，第N行的每一列都有个青蛙，这些青蛙只会往上走，上帝会在每个膜中放一个长生不老的药，一共有N个膜，每个膜覆盖一些区间，如果这个区间恰好为N那么就是好膜，否则是坏膜，每个青蛙最多只能穿过10个坏膜，问全部青蛙吃到药，并全部到顶层的分配方案。



#### 思路：

对于坏膜和好膜分开来算，先计算坏膜的方案数，然后剩下来好膜就是阶乘即可。对于坏膜，由于每列最多10个，我们对其进行状态压缩，dp[i][j]表示前第i列，且第i列中坏膜使用情况数为j的方案数。然后转移过程中需要注意每个都是相对位置。到达最后一列的应该是所有坏膜的使用的。而且在转移过程中到达一个坏膜的最右边了，那么dp[i][j]中这个膜一定是使用了的。

```C++
//题解：
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-20;
const ll _INF = 1e18;
const int INF = 1e9;
const int maxn = 1010;
const int maxm = 1e6 + 10;
const ll mod = 105225319;
int T, cas = 1;
int n, tol;
int l[maxn], r[maxn], a[maxn];
ll fac[maxn];
vector<int> g[maxn];
ll dp[maxn][1<<10];
int mp[maxn][12];
void ini(){
	fac[0] = 1;
	for(int i=1;i<maxn;++i)
		fac[i] = fac[i - 1] * i % mod;
}
int main()
{
	ini();
	scanf("%d", &T);
	while(T--){
        memset(dp,0,sizeof(dp));
		memset(a, 0, sizeof(a));
        memset(mp,0,sizeof(mp));
		scanf("%d", &n);
        for(int i=0;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;++i)
			scanf("%d", &l[i]);
		for(int i=1;i<=n;++i)
        {
			scanf("%d", &r[i]);
			if(l[i]>1 || r[i]<n){
				++a[l[i]];
				--a[r[i] + 1];
			}
        }
		bool isok = true;
		int sum = 0;
		for(int i=1;i<=n;++i){
			sum += a[i];
			if(sum > 10){
				isok = false;
				break;
			}
		}
		if(isok){
			ll ans;
			int cnt = 0;
            bool flag=false;
			for(int i=1;i<=n;++i)
            {
				if(l[i] == 1 && r[i] == n){
					++cnt;
				}
				else
                {
                    flag=true;
                    for(int j=l[i];j<=r[i];j++)
                    {
                        g[j].push_back(i);
                    }
                }
            }
			ans = fac[cnt];
			if(flag){
                int st;
                for(int i=1;i<n;i++)
                {
                    st=0;
                    for(int j=0;j<g[i].size();j++)
                    {
                        for(int k=st;k<g[i+1].size();k++)
                        {
                            if(g[i][j]==g[i+1][k])
                            {
                                mp[i][j+1]=k+1;
                                st=k+1;
                                break;
                            }
                        }
                    }
                }
				for(int i=0;i<g[1].size();i++)
                {
                    dp[1][1<<i]=1;
                }	
                dp[1][0]=1;   
 
                for(int i=1;i<n;i++)
                {
                    for(int j=0;j<(1<<g[i].size());j++)
                    {
                        if(dp[i][j])
                        {
                            int k=0;
                            bool f=true;
                            for(int pc=0;pc<g[i].size();pc++)
                            {
                                if(mp[i][pc+1])
                                {
                                    if((mp[i][pc+1]-pc-1)>=0)k|=((j&(1<<pc))<<(mp[i][pc+1]-pc-1));
                                    else k|=((j&(1<<pc))>>(-mp[i][pc+1]+pc+1));
                                }
                                else if((j&(1<<pc))==0)
                                {
                                    f=false;
                                    break;
                                }
                            }
                            if(!f)continue;
                            dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
                            for(int pc=0;pc<g[i+1].size();pc++)
                            {
                                if(((k>>pc)&1)==0)
                                {
                                    dp[i+1][k|(1<<pc)]=(dp[i+1][k|(1<<pc)]+dp[i][j])%mod;
                                }
                            }
                        }
                    }
                }
                ans=(ans*dp[n][(1<<g[n].size())-1])%mod;
			}
			printf("Case #%d: %lld\n", cas++, ans);			
		}
		else{
			printf("Case #%d: 0\n", cas++);
		}
	}
    return 0;
}
```

