#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//432b
//做桶记录 ，降时间
int n,x[100005],y[100005];
int cnt[100005];//tong  cnt[j]主场穿j 的队伍数
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++){cin>>x[i]>>y[i];cnt[x[i]]++;}

for(int i=1;i<=n;i++){
int ans_home=n-1;
ans_home+=cnt[y[i]];//客场 和别队主场相同的
int ans_away=2*(n-1)-ans_home;
cout<<ans_home<<" "<<ans_away<<endl;
}
    return 0;
}
