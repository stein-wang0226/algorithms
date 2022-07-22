#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define LOCAL
using namespace std;
//递推式  :f(n)=2*f(n-2)+f(n-1)+n^3;
//求前缀和
const long long mod = 1000000007;
long long t;
long long a, b;
long long ret[5]={0,3,1,1,1};
struct Matrix {
  long long matrix[10][10];
} ori, res;
void init() {
  memset(res.matrix, 0, sizeof res.matrix);
  for (long long i = 1; i <= 4; i++) {
    res.matrix[i][i] = 1;  //单位阵
  }
  memset(ori.matrix, 0, sizeof ori.matrix);
  for (long long i = 1; i <= 4; i++) {
    ori.matrix[1][i] = 1;
  }
  for (long long i = 2; i <= 4; i++) {
    ori.matrix[2][i] = 1;
  }
  ori.matrix[3][2] = ori.matrix[4][3] = 1;
}

Matrix mul(Matrix a, Matrix b) {
  Matrix ret;
  memset(ret.matrix, 0, sizeof ret.matrix);
  for (long long i = 1; i <= 4; i++) {
    for (long long k = 1; k <= 4; k++) {
      if (a.matrix[i][k])
        for (long long j = 1; j <= 4; j++) {
          ret.matrix[i][j] +=
              ((a.matrix[i][k]) % mod * (b.matrix[k][j]) % mod) %
              mod;  //都取模防溢出
          ret.matrix[i][j] %= mod;
        }
    }
  }
  return ret;
}

void ksm(Matrix a, long long k) {
  while (k) {
    if (k & 1) res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> a >> b) {
    long long ans1=0;
    if(a<4)ans1=a;
    else{
    init();
    ksm(ori, a - 3);
    
    for(long long i=1;i<=4;i++){
      ans1+=res.matrix[1][i]*ret[i];
      ans1%=mod;
    }
    }
     long long ans2=0;
    if(b<3)ans2=b+1;
    else{
    init();
    ksm(ori, b - 2);
    for(long long i=1;i<=4;i++){
      ans2+=res.matrix[1][i]*ret[i];
      ans2%=mod;
    }
    }
    long long ans=(ans2-ans1);
    if (ans<0)ans+=mod;//防负数
    cout<<ans<<endl;
    
  }
  return 0;
}
