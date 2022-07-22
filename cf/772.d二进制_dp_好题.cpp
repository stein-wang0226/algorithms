#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
//  二进制
//操作2等价于末尾加1
//操作1等价于末尾++00
//dp ·考虑一个数增长i位种数dp[i]  则有dp[1]=1 (1),dp[2]=2,(00/11),dp[3]=dp[1]+dp[2]=2 ,dp[n]=dp[n-1]+dp[n-2](fibo)  在n-1位 后面加1 或n-2位后面+00  
// 在用sum储存种数的前缀和  sum[i] 表示p-i 位的数能产生的数总个数
//  同一个数操作产生的数不会重复（增加）   但二进制前缀相同的数产生的数会重复
//所以若干次操作的前缀相同的只对短的根节点操作 eg: 100  1001 10000 100100 只保存100
const int N=2e5+5;
const int mod= 1e9+7;
int T,n,p;
int dp[N],sum[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>p;
vector<int>a(n);
set<int>st;
for(int i=0;i<n;i++){
    cin>>a[i];
    st.insert(a[i]);// 先去一次重
}

//预处理里 dp数组   (fibo)
dp[1]=1,dp[2]=2;
for(int i=3;i<=p;i++)
{
    dp[i]=(dp[i-1]+dp[i-2])%mod;
}
sum[0]=1;
for(int i=1;i<=p+1;i++){//  处理好每种二进制长度对应的答案
    sum[i]=(sum[i-1]+dp[i])%mod;
}

sort(a.begin(),a.end());  //加快效率
for(int i=0;i<n;i++){//第二次去重 (产生同样后代的)  只保留根节点
    int t=a[i]; 
    while(t){//不断作逆操作找根节点
    if(t%2==1){// 1
        t>>=1;
    }
    else if(t%4==0){//2
        t>>=2;
    }
    else break;   //  不能继续逆操作跳出（到达根结点）
    if(st.count(t)){st.erase(a[i]);break;}  //根节点已存在 去重
    }
}
int ans=0;
for (auto i:st){
    int bit=log2(i)+1;//a[i]   的二进制位数
    int k=p-bit;//  空余位数
   if(k>=0) ans+=sum[k]%mod,ans%=mod;   //满足的（小于p位）的答案加上
   
}
cout<<ans%mod<<endl;
    return 0;
}
