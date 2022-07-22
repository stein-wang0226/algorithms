#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 2e6 + 5;
int T, n,m;
int stmax[N][22];  //区间[ i , i + 2 ^j − 1 ] 的最大值
int stmin[N][22];
int logn[N];  // 存向下取整的log
int a[N];
void init() {  //预处理log2  初始化st[i][0]
  logn[0] = -1;  //这样 log[1] 为0
  for (int i = 1; i <= n; i++) {
    logn[i] = logn[i / 2] + 1;  // 也可以这样mn[i] = ((i & (i - 1)) == 0) ? mn[i- 1] + 1 : mn[i - 1]
    stmax[i][0] = stmin[i][0] = a[i];
  }
  

  //  nlogn 预处理st
  for (int j = 1; j <= logn[n]; j++) {  // 范围不用超过n  长度从小到大更新
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {// 长度  2^j
      stmax[i][j] =    max(stmax[i][j - 1], stmax[i + (1 << j-1)][j - 1]);  //左右更新
      stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int rmq_max(int L,int R){  // 查询
  int k=logn[R-L+1]; // >=长度的log
  return max(stmax[L][k],stmax[R-(1<<k)+1][k]);
  //*** 可重复更新
}
int rmq_min(int L,int R){  // 查询  相同
  int k=logn[R-L+1]; // >=长度的log
  return min(stmin[L][k],stmin[R-(1<<k)+1][k]);
  //*** 可重复更新
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>n>>m;

for(int i=1;i<=n;i++)cin>>a[i];
init();// 输入后初始化
for(int i=1;i<=m;i++){
int l,r;
cin>>l>>r;
cout<< rmq_max(l,r)<<endl;
}

  return 0;
}
