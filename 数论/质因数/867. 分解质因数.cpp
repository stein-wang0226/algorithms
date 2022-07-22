#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
//试除法判分解质因数  从小到达枚举所有质因数（到 sqrt(n)）
using namespace std;
void divide(int n){
    for(int i=2;i<=n/i;i++){//每次将质数除干净  不会出现合数
        if(n%i==0){
            int cnt=0;
            while(n%i==0)n/=i,cnt++;
        cout<<i<<" "<<cnt<<endl;
        }
    }
    if(n>1)cout<<n<<" "<<1<<endl;//   可能还剩一个
    cout<<"\n";
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
cin>>n;
while(n--){
    int k;
    cin>>k;
    divide(k);
}
    return 0;
}
