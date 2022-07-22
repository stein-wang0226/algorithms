#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//n - 1 个点，从 2 到 n，点 a 与点 b 的边权为 lcm(a,b),求出 n−1 个点的最小生成树
//从小到大 若x为素数 则肯定和2连  +2*x   若为合数 与之前因子连即可   +x 线性筛求素数
const int N = 1e7 + 5;
int T, n, a[N];
int prime[N],vis[N],cnt;
int sum[N]; //2~到n 的素数和
int Sum;
void get_prime(int n){
    for(int i=2;i<=n;i++){ //2的贡献是0
        if(!vis[i]){prime[++cnt]=i;//未标记就加入
               if(i>2) Sum+=i;   //大于2 的加上
        }
        sum[i]=Sum;  //记录n之前的素数和
        for(int j=1;prime[j]<=n/i;j++){// **每次用 prime[j] 作k=prime[j]*i 的最小质因子筛k
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break; //prime[j]已是i的最小质因子 不能继续  优化为线性  (防止重复标记)
        }
    }
}
void solve(){
cin>>n;

int ans=0;
if(n!=2){
    ans=(3+n)*(n-2)/2+sum[n];
}
cout<<ans<<endl;


}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


    Sum=0;
    get_prime(1e7);
  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
