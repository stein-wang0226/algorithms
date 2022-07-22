#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int inf=0x3f3f3f3f;
//d
//将每个元素与x做差，转化为求最大(任意连续子串为正)的子序列----简单dp**
//因为任意子串为正，只需保证当前要加入元素i与当前答案串的最后一位和最后两位之和大于=0
//dp储存 后两位
int x,t,n,a[50005],ans[50005],dp[50005],dp1,dp2;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>x;
     for(int i=1;i<=n;i++)a[i]-=x;
int cnt=0;

dp1=inf;dp2=a[1];
int flag=0;
    for(int i=2;i<=n;i++){
        if(a[i]+dp1+dp2>=0&&a[i]+dp2>=0){//讨论当前与后两位的关系
        if(flag){ 
            ans[++cnt]=dp1;
            dp1=dp2;
            dp2=a[i];}
        else{
            dp1=dp2;
            dp2=a[i];
        }
        flag=1;
    }
        //else if(a[i]+dp2>=0&&a[i]+dp1+dp2<0){//说明dp2>0
        //     dp1=dp2;
        //     dp2=a[i];
        // }
        else if(a[i]+dp1+dp2>=0&&a[i]+dp2<0)//舍弃dp2
    {
        dp2=max(dp2,a[i]);
    }
    }
    ans[++cnt]=dp1;ans[++cnt]=dp2;
    cout<<cnt<<endl;
    // for(int i=1;i<=cnt;i++)cout<<ans[i]<<" ";
    // cout<<endl;
}
    return 0;
}
