#include <bits/stdc++.h>
#define LOCAL
//define int long long
using namespace std;
//只需看前 n-10 个数  若8的个数大于(n-11)/2 yes 否则no
//因为后10为不会对开头是否8产生影响
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
string  s;
cin>>n;
cin>>s;
int cnt=0;
for(int i=0;i<n-10;i++){
    if(s[i]=='8')cnt++;
}

if(cnt>(n-11)/2)cout<<"yes"<<endl;
else cout<<"no"<<endl;
    return 0;
}
