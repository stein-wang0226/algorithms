#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
using namespace std;
//离散化模板
const int N=1e5+5;
struct  node{
    int val,id;//原下标
    bool operator <(const node&b)const{
        return val<b.val;
    }
}a[N];
int b[N];//b[i]  原下标i对应的新下标（按序）
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
cin>>n;
for(int i=1;i<=n;i++){
    a[i].id=i;
    cin>>a[i].val;
}
sort(a+1,a+1+n);
b[a[1].id]=1;  
for(int i=2,cnt=1;i<=n;i++){
    if(a[i].val==a[i-1].val) b[a[i].id]=cnt;     //重复
    else b[a[i].id]=++cnt;    
}

for(int i=1;i<=n;i++)cout<<b[i]<<" ";


    return 0;
}
