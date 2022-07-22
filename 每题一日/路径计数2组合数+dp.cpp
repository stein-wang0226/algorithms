#include <bits/stdc++.h>
#define LOCAL
#define int long long
typedef long long LL;
// 不能开dp[][]跑dp  
//  考虑到无障碍两点间种数为 C(x2-x1+y2-y1,x2-x1 )
//  ***考虑用 dp[i]表示从起点 不经过其他障碍**到第i个障碍的方法数
// 不仅过之前的  不需要容斥 刚好是所有情况 (第一步到第j个障碍的非法情况)
// 可以先用到第i个障碍的总数-途径j障碍的方案数  ()
// 将终点看作 m+1个障碍  答案为dp[m+1]
// 排序后dp即可
using namespace std;
const int N=1e5+5;
const int M=3005;
const int mod=1e9+7;
int T,n,dp[M],m;
int fact[4*N],infact[4*N];  //
struct Node{
    int x,y;
    bool operator <(const Node&b)const{
            return x+y<b.x+b.y;
    }
}node[M];
int qpow(int a,int k){
    int res=1;
    while(k){
        if(k&1)res=(res*a)%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}
LL cal(int a,int b){
	LL res=(LL)(LL)fact[a]*infact[b]%mod*infact[a-b]%mod;
	return res;
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    fact[0]=infact[0]=1;
    for(int i=1;i<N*4;i++){//预处理阶乘
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i]=(LL)infact[i-1]*qpow(i,mod-2)%mod;//费马小定理 (mod为质数)
    }
cin>>n>>m;
for(int i=1;i<=m;i++){
    cin>>node[i].x>>node[i].y;
}
node[m+1].x=n;node[m+1].y=n;
sort(node+1,node+2+m);
for(int i=1;i<=m+1;i++){
    int x1=node[i].x,yy1=node[i].y;
    int res=cal(x1-1+yy1-1,x1-1)%mod;
    for(int j=1;j<i;j++){
        int x2=node[j].x,y2=node[j].y;
        if(x1>=x2&&yy1>=y2)res=(res+mod-((dp[j]%mod)*(cal(x1-x2+yy1-y2,x1-x2)%mod))%mod)%mod;  // 经过j再到i
    }
    dp[i]=res%mod;
}

cout<<dp[m+1]%mod<<endl;
    return 0;
}
