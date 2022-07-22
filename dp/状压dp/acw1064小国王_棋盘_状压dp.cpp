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
int check(int state){
    for(int i=1;i<=n;i++){
        if((state>>(i-1)&1)&&(state>>i&1))return 0;  //不能存在相邻1
    }
    return 1;
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
    for(int i=0;i<state.size();i++){
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
