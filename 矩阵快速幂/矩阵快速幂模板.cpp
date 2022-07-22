#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t, n, k;
const int N = 10;
const int mod=9973;
//矩阵快速幂模板
struct Matrix {  //便于返回和初始化
  int matrix[15][15];
} ori, res;                                  //读入矩阵和结果矩阵
void init(int n) {                           //初始化
  memset(res.matrix, 0, sizeof res.matrix);  //
  for (int i = 1; i <= n; i++) {
    res.matrix[i][i] = 1;  //单位矩阵
  }
}

Matrix  multiple(Matrix a,Matrix b){// 矩阵乘法返回矩阵 
Matrix ret;
memset(ret.matrix,0,sizeof ret.matrix);////初始化为0
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            ret.matrix[i][j]+=(a.matrix[i][k]*b.matrix[k][j])%mod;
        ret.matrix[i][j]%=mod;
        }
    }
}
return ret;
}

void Matrix_ksm(Matrix m,int k){//快速幂

    while(k){
        if(k&1){//奇数   最后k=1会将最后m乘上
            res=multiple(m,res);
        }
        m=multiple(m,m);//
        k>>=1;
    }
    int ans=0;//内部输出   返回矩阵也可
    for(int i=1;i<=n;i++){
        ans+=(res.matrix[i][i])%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> k;
    init(n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> ori.matrix[i][j];
      }
    }
    Matrix_ksm(ori,k);
    
  }
  return 0;
}
