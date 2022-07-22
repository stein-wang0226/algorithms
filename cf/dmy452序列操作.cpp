#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
const int N=2e6+5;
int T,n;
int q,a[N];
int order[N];// 第i个数最后的操作一时间
//最后肯定是最后的操作一或 最后一次操作一后操作2的最大者
//存操作二后缀最大值
int maxx[N];//操作二 后缀最大值
signed main(){
    std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>a[i];
vector<pair<int,int>>b;
memset(order,0,sizeof order);
b.push_back({0,0});
for(int i=1;i<=q;i++){
    char s;cin>>s;
    int x,y;
    if(s=='1'){
        cin>>x>>y;
        a[x]=y;
        order[x]=i;
    }
    else if(s=='2'){
        int y;cin>>y;
        b.push_back({i,y});
    }
}
//处理后缀最大值
memset(maxx,0,sizeof maxx);  // 为赋值说明之后无操作22  
int len=b.size();
int Max=b[len-1].second; // 从后往前处理后缀
for(int i=len-1;i>=1;i--){//
    Max=max(Max,b[i].second);
    for(int j=b[i].first;j>=b[i-1].first;j--){
    maxx[j]=Max;
    }
}
for(int i=1;i<=n;i++){
    int ans=max(a[i],maxx[order[i]]);
    cout<<ans<<" ";
}
cout<<endl;


    return 0;
}
