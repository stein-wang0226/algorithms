#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//779c策略 贪心 排序
//先将k个 now-after 最小的加上，之后n-k个加 前后最小值即可
struct node{
    int now,after,cha,minn;
    bool operator <(const node&b)const{
        return cha<b.cha;
    }
}a[200005];
int n,k;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i].now;
}
for(int i=1;i<=n;i++){
    cin>>a[i].after;
    a[i].cha=a[i].now-a[i].after;
    a[i].minn=min(a[i].now,a[i].after);
}
sort(a+1,a+1+n);
long long ans=0;
for(int i=1;i<=n;i++){
    if(i<=k){
        ans+=a[i].now;
    }
    else ans+=a[i].minn;
}
cout<<ans<<endl;
    return 0;
}
