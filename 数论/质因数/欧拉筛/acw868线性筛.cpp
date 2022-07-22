#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//线性筛--欧拉筛 更快
//方法  用n的最小质因子筛n***  （防重复）
const int N=1e6+5;
int prime[N],vis[N],cnt;

void get_prime(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i])prime[++cnt]=i;//未标记就加入
        for(int j=1;prime[j]<=n/i;j++){// **每次用 prime[j] 作k=prime[j]*i 的最小质因子筛k
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break; //prime[j]已是i的最小质因子 不能继续  优化为线性  (防止重复标记)
        }
    }
}
using namespace std;
int T,n;
signed main(){
    cin>>n;
    get_prime(n);
    cout<<cnt<<endl;
    //for(int i=1;i<=cnt;i++)cout<<prime[i]<<" ";
    return 0;
}
