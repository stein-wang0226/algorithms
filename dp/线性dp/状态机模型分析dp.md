# 状态机模型分析dp/自动机

## 	例题1. acw 1049 大盗阿福

[大盗阿福]:https://www.acwing.com/activity/content/problem/content/1287/

 题意：给定一个长度为 N 的数组，数组中的第 i 个数字表示一个给定股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润，你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。一次买入卖出合为一笔交易。.线性dp解法

### 方法1：线性dp

#### 状态定义：

dp[i]:为前i家店可以取得的最大收益

#### 状态转移

1.如果抢劫第i家店则dp[i]=dp[i-2]+ w[i],因为抢不了第i-1家店所以答案为前i-2家店可获得前加上第i家店的收益
2.如果不抢第i家店则dp[i]=dp[i-1]  

```C++
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int num[N],dp[N];
int main()
{
    
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
        dp[1]=num[1];
        for(int i=2;i<=n;i++)
        dp[i]=max(dp[i-2]+num[i],dp[i-1]);
             
        cout<<dp[n]<<endl;
    }
}

```

### 方法2**.状态机分析**

1,dp [i] [0]表示不抢劫第i家店可获得的最大金钱

2. dp [i] [1]表示抢劫第i家店可获得的最大金钱

![image-20220501203044167](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20220501203044167.png)

```C++
#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=0x3f3f3f3f;
int num[N],dp[N][2];
int main()
{
    
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
       dp[0][1]=-inf;dp[0][0]=0;
       for(int i=1;i<=n;i++)
       {
           dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
           dp[i][1]=dp[i-1][0]+num[i];
       }
       cout<<max(dp[n][0],dp[n][1])<<endl;
    }
}

```



与没有上司的舞会类似



## 例题2.1057.股票买卖 IV***

[股票买卖 IV]:https://www.acwing.com/activity/content/problem/content/1288/

给定一个长度为 N 的数组，数组中的第 i 个数字表示一个给定股票在第 i天的价格。

设计一个算法来计算你所能获取的最大利润，你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。一次买入卖出合为一笔交易。

### 思路：

 决策：在完成第 i 天的决策后，状态是持仓(k=1)还是空仓(k=0)

#### 状态表示

dp [i] [j] [k]： 考虑前 i 天的股票，第 i 天的 决策 是 k，且完成的 完整交易数 为 j 的方案

那么如何利用该状态表示出题设中的状态转移行为呢？

买入行为：k=0 →→ k=1
		卖出行为：k=1 →→ k=0
		持仓行为：k=1 →→ k=1
		空仓行为：k=0 →→ k=0

#### 状态计算：

```C++
dp[i] [j] [0] =max(dp[i-1] [j] [0] ,dp[i-1]  [j-1]  [1]+w[i]  )  //空仓 第i-1天买与不买转化而来
dp[i][j][j]=max(dp[i-1][j][1],dp[i-1][j][0]); //持仓 第i-1天买与不买转化而来
```

![image-20220501204811330](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20220501204811330.png)

```C++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 110;

int n, k;
int w[N];
int f[N][M][2];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> w[i];

    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0; //初始状态f[0][0][0]  入口

    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 0; j <= k; ++ j)
        {
            f[i][j][0] = f[i - 1][j][0];
            if (j) f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
        }
    }

    int res = 0;
    for (int j = 0; j <= k; ++ j) res = max(res, f[n][j][0]); //目标状态f[n][j][0]

    cout << res << endl;

    return 0;
}

//可以滚动优化
```



### 例3.1058. 股票买卖 V

[股票买卖 V]:https://www.acwing.com/activity/content/problem/content/1289/

给定一个长度为 N 的数组，数组中的第 ii 个数字表示一个给定股票在第 i 天的价格。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

- 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 11 天)。
- //不限制总数  

#### 思路：

**第 i 天的 决策状态：**
       **(j=0) 当前没有股票，且不处于冷冻期 （空仓）**
       **(j=1) 当前有股票 （持仓**
       **(j=2) 当前没有股票，且处于冷冻期 （冷冻期**

注意：这里的 冷冻期 状态，实际意义是指当天卖出了股票，所以 后一天是没法交易

#### 状态机模型分析：

![image-20220501235155987](C:\Users\86172\AppData\Roaming\Typora\typora-user-images\image-20220501235155987.png)如果第 i 天是 空仓 (j=0) 状态，则 i-1 天可能是 空仓 (j=0) 或 冷冻期 (j=2) 的状态
如果第 i 天是 冷冻期 (j=2) 状态，则 i-1 天只可能是 持仓 (j=1) 状态，在第 i 天选择了 卖出
如果第 i 天是 持仓 (j=1) 状态，则 i-1 天可能是 持仓 (j=1) 状态 或 空仓 (j=0) 的状态 （买入）

#### 状态表示：

dp[i] [j]  前i天状态是j的方案最大利润

#### 状态转移：

dp[i] [0] =max(dp[i-1] [0], dp[i-1] [2]) //空仓只可能由空仓或冷冻期转移

dp[i] [1]=max(dp[i-1] [1],dp[i-1] [0]-w[i] ) // 持仓可能由持仓 和空仓转移

dp[i] [2]=dp[i-1] [1]+w[i]; //冷冻只能由持仓转移  

```C++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 110;
int n, k;
int w[N];
int dp[N][3];
int main(){
    memset(dp,-0x3f,sizeof dp); //初始化-inf
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    dp[0][0]=0; //初始入口  空仓
    //转移
    for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0], dp[i-1][2]);//空仓只可能由空仓或冷冻期转移
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-w[i]);// 持仓可能由持仓 和空仓转移
    	dp[i][2]=dp[i-1][1]+w[i]; ////冷冻只能由持仓转移 (卖出) 
    }
    int ans=max(dp[n][0],dp[n][2]); //最后持仓不可能最优
    cout<<ans<<endl;
    return 0;
}
//显然可以滚动一维
```



### 例4： AcWing 1052. 设计密码

[设计密码]:https://www.acwing.com/problem/content/1054/

你现在需要设计一个密码 SS，SS 需要满足：

- SS 的长度是 N；
- SS 只包含小写英文字母；
- SS 不包含子串 T；

例如：abc 和 abcde 是 abcde 的子串，abd 不是 abcde 的子串。

请问共有多少种不同的密码满足要求？

由于答案会非常大，请输出答案模 109+7109+7 的余数。

#### 多个状态的自动机：结合kmp





























### 例5. AcWing 1052. 设计密码

[设计密码]:https://www.acwing.com/activity/content/problem/content/1290/

ac自动机
