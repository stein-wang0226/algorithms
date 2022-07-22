#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//思维
//定义f(n,l)第n秒后第l个位置的状态
//状态方程 : f(n,l)= f(n,l) +0  f(n-1,l-1)==0
// 1-f(n-1,l)     f(n-1,l-1)==1
//由同余性质简化  递推式 f(n,l)=f(n-1,n-1)+f(n-1,l)
//   二维状态  dp[][]
int n,l;
string s;
struct Matrix {
  long long matrix[105][105];
} ori, res;
void init(int l) {  //初始化 矩阵
  memset(res.matrix, 0, sizeof res.matrix);
  memset(ori.matrix, 0, sizeof ori.matrix);
  for (int i = 1; i <= l; i++) res.matrix[i][i] = 1;
  ori.matrix[1][1] = ori.matrix[1][l] = 1;
  for (int i = 2; i <= l; i++) {
    ori.matrix[i][i - 1] = ori.matrix[i][i] = 1;

  }
}

Matrix mul(Matrix a, Matrix b) {
  Matrix ret;
  memset(ret.matrix, 0, sizeof ret.matrix);
  for(int i=1;i<=l;i++){
      for(int j=1;j<=l;j++){
          for(int k=1;k<=l;k++){
                ret.matrix[i][j]^=(a.matrix[i][k])*(b.matrix[k][j]);//相当于相加模2
          }
      }
  }
  return ret;
}

void ksm(Matrix a,long long k){
        while(k){
            if(k&1)res=mul(res,a);
            a=mul(a,a);
            k>>=1;
        }
}
int ret[105];  //当前状态
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> n) {
    cin >> s;
    l = s.size();
    for (int i = 0; i < s.size(); i++) {//读入串
      ret[i + 1] = s[i] - '0';
    }
    init(l);
    ksm(ori,n);
    int ans[105];
    memset(ans,0,sizeof ans);
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            ans[i]^=res.matrix[i][j]*ret[j];
        }
    }
    for(int i=1;i<=l;i++){
        cout<<ans[i];
    }
    cout<<endl;
  }
  return 0;
}
