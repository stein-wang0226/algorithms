#include<bits/stdc++.h>
# define int long long
using namespace std;
// 指数 小于k的质因子舍去
int n,k;
int T;
signed main(){
    cin>>T;
    while(T--){

        cin>>n>>k;
        int to_div = 1;
        int tmp=n;
        for(int i=2;i<=tmp/i;i++){ // tmp 而非n  更快
            int cnt = 0;
            int res =1;
            while(tmp%i==0){
                tmp/=i;cnt++;
                res*=i; // 可能删除的部分
            }
            if(cnt<k) to_div*=res;
        }
        if(tmp>1&&k>1)n/=tmp;//   这里自身可能还剩一个质数 除掉
        cout<<n/to_div<<endl;

    }




    return 0;
}