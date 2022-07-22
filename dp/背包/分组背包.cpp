#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e2+5;
int V,n;
int s[N],v[N][N],w[N][N];
int dp[N]; //滚动一维
//分组背包 每次一组一组更新背包
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>V;
for(int i=1;i<=n;i++){
    cin>>s[i];
    for(int j=1;j<=s[i];j++){
        cin>>v[i][j]>>w[i][j];
    }
}
//w[0][]   v[0][0]  初值都为0
for(int i=1;i<=n;i++){//枚举每一组
    for(int j=V;j>=0;j--){// 倒序枚举体积
        for(int k=1;k<=s[i];k++){// 枚举选哪个或不选
        if(j>=v[i][k])//能装下
            dp[j]=max(dp[j],dp[j-v[i][k]]+w[i][k]);
        }
    }
}
cout<<dp[V]<<endl;
    return 0;
}
