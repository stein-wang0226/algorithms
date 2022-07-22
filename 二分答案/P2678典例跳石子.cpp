#include <cstdio>
#include <ctime>
#include <iostream>  //典型二分：最小值最大 模板1
#define LOCAL
const int Max = 5e5 + 5;
using namespace std;
int m, n;
long long L, d[Max], len[Max],len2[Max];  // len为相邻石块距离，即找len最小值的最大值 len2 以便重复操作
int check(//***难点，使每个len都小于mid，最短距离显然小于mid
    int mid) {  //模拟一整次跳跃和搬石头,判断mid是否在(m以内操作)的最短距离区间
  int cnt = 0;  //搬的个数
  for (int i = 1; i <= n+1; i++) {
    if (len2[i] < mid) {  //太短就搬i 看能否使最短距离大于mid（使位于合法范围）
      len2[i + 1] = len2[i] + len2[i + 1];  //搬后距离
      cnt++;
    }
  
  }
  if (cnt <= m)
    return 1;  //***能在m次以内操作,使mid小于操作后最短距离
               //即mid在(m以内操作)的最短距离区间
    return 0;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> L >> n >> m;
  d[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    len[i] = d[i] - d[i - 1];
  }
  len[n+1]=L-d[n];//读题 第n块到终点距离
  int l = 1;
  int r = L;
  while (l < r) {
    for(int i=1;i<=n+1;i++)len2[i]=len[i];//注意时间，其实有更好的方法
    int mid = (r + l + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l;

  return 0;
}
