#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//lowbit 求二进制中1的个数
int lowbit (int x){
    return x& -x;
}
int m,n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){
    cin>>m;
    int res=0;
    while(m){
        m-=lowbit(m),res++;
    }
    cout<<res<<" ";
}
    return 0;
}
