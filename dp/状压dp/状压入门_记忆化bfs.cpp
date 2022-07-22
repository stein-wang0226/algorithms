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
