#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int T,n;
int a[N];
int sum[N];
int cnt[N][30];//前缀中每一位1的个数
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    
#endif
cin>>n;
int maxbit;
for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=(sum[i-1]%mod+a[i])%mod;
int bit=0;// 位数从0楷书
int temp=a[i];
while(temp){
    cnt[i][bit]=cnt[i-1][bit]+(temp%2);// 1的个数
    temp>>=1;
bit++;
}
maxbit=max(maxbit,--bit);
}

int ans=0;
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        int res1=(sum[j]-sum[i-1]);
        int res2=0;
        int temp=1;
        for(int k=0;k<=maxbit;k++){
            int count=cnt[j][k]-cnt[i-1][k];//区间每一位1的总数
            if(j-i+1==count)res2+=temp;      // 全1
            temp<<=1;
        }
        ans+=(res2%mod)*(res1%mod);
        ans%=mod;

    }
}

cout<<ans%mod<<endl;






    return 0;
}
