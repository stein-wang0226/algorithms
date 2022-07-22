#include <bits/stdc++.h>
//#define LOCAL
#define int long long
//连通块中点的数量
//合并时维护个数即可
using namespace std;
const int N=2e5+5;
int pre[N],sum[N];
int m,n;
int find(int x){
    while(x!=pre[x]){
        pre[x]=pre[pre[x]];//压缩
        x=pre[x];
    }
    return x;
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
for(int i=1;i<=n;i++){pre[i]=i;sum[i]=1;}
string s;
int a,b;
for(int i=1;i<=m;i++){
cin>>s;
if(s=="C"){
    cin>>a>>b;
    if(find(a)!=find(b))//注意
    sum[find(a)]+=sum[find(b)],//
    pre[find(b)]=find(a);
    
}
else if(s=="Q1"){
    cin>>a>>b;
    if(find(a)==find(b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
else if(s=="Q2"){
    cin>>a;
    cout<<sum[find(a)]<<endl;
}
}
    return 0;
}
