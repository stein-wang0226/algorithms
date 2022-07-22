#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e3 + 5;
// 数每条斜线（n）上递增1的最大值
int T, n, a[N];
char Map[N][N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    cin >> n;
       int tot1=0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> Map[i][j];
          if(Map[i][j]=='1')tot1++;
      }
    }
    int maxx=0;
    for(int i=0;i<n;i++){// 对应n条斜线  相对对角线向右偏移量
        int cnt=0;
      for(int j=1;j<=n;j++){ // 行
        int k=(i+j-1)%n+1; //每行列号
        if(Map[j][k]=='1')cnt++;
      }
      maxx=max(maxx,cnt);
    }

  int ans=(tot1-maxx)+(n-maxx);
  cout<<ans<<endl;
  }
  return 0;
}
