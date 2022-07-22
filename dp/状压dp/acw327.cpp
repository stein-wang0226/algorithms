#include <bits/stdc++.h>
//# pragma GCC optimize(3)
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
