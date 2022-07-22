#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 偶数次移动 移动后位置奇偶性不变**
// 所以分别按奇数位偶数位排序后判断是否有序
using namespace std;
const int N=1e5+5;
int T,n;
int a[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
vector<int>aa;
vector<int>b;
for(int i=1;i<=n;i++){
cin>>a[i];
if(i%2)aa.push_back(a[i]);
else b.push_back(a[i]);
}
sort(aa.begin(),aa.end());
sort(b.begin(),b.end());
vector<int>res;
int cnt1=0,cnt2=0;
for(int i=1;i<=n;i++){
    if(i%2)res.push_back(aa[cnt1++]);
    else res.push_back(b[cnt2++]);
}
if(is_sorted(res.begin(),res.end()))cout<<"YES"<<endl;
else  cout<<"NO"<<endl;



}

    return 0;
}
