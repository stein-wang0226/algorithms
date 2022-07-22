#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
//只能向右下走
//所以从有下到左上递推
// dp[i][j]  i，j到 r，c的最小期望花费

const int N = 1005;

int T, n, a[N],m;
double dp[N][N];
double p1[N][N],p2[N][N],p3[N][N];
signed main() {

while(scanf("%d%d",&n,&m)!=EOF){
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          //  cin>>p1[i][j]>>p2[i][j]>>p3[i][j];
              scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);
        }
    }

    dp[n][m]=0;
    for(int i=n;i>0;i--){  //从右下方开始
        for(int j=m;j>0;j--){
            if(i==n&&j==m)continue;
            if(fabs(p1[i][j]-1)<1e-7)continue;  //P1为1说明不能及继续移动
            dp[i][j]=(p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2)/(1-p1[i][j]); // (+2:，移动必须)
            //由dp[i][j]=p1[i][j]*dp[i][j]+p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2 递推得到
        }
    }
    printf("%.3lf\n",dp[1][1]);
}
  return 0;
}
