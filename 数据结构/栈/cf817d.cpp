#include <bits/stdc++.h>
#define LOCAL
#define int long long
// 求所有子串的最大值最小值之差
//因为每个最大，小值独立
//只需分别求所有最大值之和减最小值之和
//单调栈 最大值  求每个元素作前/后最大值的最大范围
//即对每个元素求之前/后最后一个小于他的位置 l[i]   r[i]  则(串个数)ans+=a[i]×（i - L[i]+1）×（R[i] - i+1 )
//注意定义大小相同情况   左<= 右<
using namespace std;
const int N=1e6+5;
int T,n,a[N];
int l[N],r[N];
int stk[N],tt;
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){cin>>a[i];}
// max  l  之前第一个大于的位置+1 
tt=0;
for(int i=1;i<=n;i++){
    while(tt&&a[stk[tt]]<=a[i]){
        tt--;
    }
    if(tt)l[i]=stk[tt]+1;
    else l[i]=1;
    stk[++tt]=i;
}
tt=0;//求 r
for(int i=n;i>=1;i--){// 
    while(tt&&a[stk[tt]]<a[i]){
        tt--;
    }
    if(tt)r[i]=stk[tt]-1;
    else r[i]=n;
    stk[++tt]=i;
}
int ans=0;
for(int i=1;i<=n;i++){
ans+=a[i]*(i-l[i]+1)*(r[i]-i+1);
}
//  同理求 min
tt=0;
for(int i=1;i<=n;i++){
    while(tt&&a[stk[tt]]>a[i]){
        tt--;
    }
    if(tt)l[i]=stk[tt]+1;
    else l[i]=1;
    stk[++tt]=i;
}
tt=0;//求 r
for(int i=n;i>=1;i--){// 
    while(tt&&a[stk[tt]]>=a[i]){
        tt--;
    }
    if(tt)r[i]=stk[tt]-1;
    else r[i]=n;
    stk[++tt]=i;
}
for(int i=1;i<=n;i++){
ans-=a[i]*(i-l[i]+1)*(r[i]-i+1);
}
cout<<ans<<endl;
    return 0;
}
