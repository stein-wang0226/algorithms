#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//依赖背包  ：买一样物品前要先买另一样
const int N = 1e5 + 10;
int dp[55][N];  //前i个箱子花费j得到的最大价值
int box[55];//箱子价值
int c[55][20],v[55][20]; //价格  价值
int num[55];
int T, n, W;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

while(cin>>n>>W){
memset(dp, 0, sizeof(dp));			//初始化

for(int i=1;i<=n;i++){
    cin>>box[i]>>num[i];
    for(int j=1;j<=num[i];j++)
        cin>>c[i][j]>>v[i][j];
    
}
for(int i=1;i<=n;i++){
    for(int j=0;j<box[i];j++)dp[i][j]=-1; //总费用小于box无法购买该盒子内物品

    for(int j=box[i];j<=W;j++){//类似01背包  先假设选这个箱子
        dp[i][j]=dp[i-1][j-box[i]];   //选择盒子后的价值 （不用比较
    }
   //01;背包
    for(int k=1;k<=num[i];k++){// 每个物品
        for(int j=W;j>=c[i][k];j--){ //从大到小更新体积
            if(dp[i][j-c[i][k]]!=-1) //有箱子
           {
                dp[i][j]=max(dp[i][j],dp[i][j-c[i][k]]+v[i][k]);
           }
        }
    }
for(int j=0;j<=W;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);//于不选该箱子做比较
}
cout<<dp[n][W]<<endl;
}
  return 0;
}
