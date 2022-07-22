#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=5e5+5;
//离散化 模板二（常用）

int n,a[N],b[N],Rank[N];//b 为排序后   Rank为离散化后
//  b[Rank[i]]为离散化前的值
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif


cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
}
sort(b+1,b+1+n);
int len=unique(b+1,b+1+n)-(b+1);   //去重，得长度
for(int i=1;i<=n;i++){
    Rank[i]=lower_bound(b+1,b+1+len,a[i])-b;//  得离散化后数组 （从1开始） 
}

for(int i=1;i<=len;i++)cout<<Rank[i]<<" "; 
    return 0;
}




 //jiangly代码

    //离散化
    auto v = s;
    std::sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        s[i] = std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();
    }
