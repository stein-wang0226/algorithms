#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//最长的不包含重复的数的连续区间的长度。
using namespace std;
const int N=1e5+5;
int a[N],n,s[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
memset(s,0,sizeof s);
for(int i=1;i<=n;i++){
    cin>>a[i];

}
int res=0;
for(int j=1,i=1;i<=n;i++){//区间结尾
    s[a[i]]++;
    while(j<i&&s[a[i]]>1){//出现重复
        s[a[j++]]--;   //  j（开头）后移一位  
    }
    res=max(res,i-j+1);
}
cout<<res<<endl;

    return 0;
}
