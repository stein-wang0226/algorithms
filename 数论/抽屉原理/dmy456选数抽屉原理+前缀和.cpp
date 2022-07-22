#include <bits/stdc++.h>
#define LOCAL
#define int long long

//抽屉原理 +前缀和
////前缀和mod n  由于对n取模只有n种答案 所以 1.出现0 则 这一段前缀为一种答案  2. 不含0 则必有两个元素相同则这段区间为合法答案
using namespace std;
const int N=1e5+5;
int a[N];
int pos[N];
//出现次数int 
int T,n;
signed main(){
    std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
int sum=0;
pos[0]=0;//0 出现0从1到i
for(int i=1;i<=n;i++){
    cin>>a[i];
    sum+=a[i];
    sum%=n;
    if(!sum||pos[sum]){// sum 为0或之前已出现+
        cout<<i-pos[sum]<<endl;
        for(int j=pos[sum]+1;j<=i;j++)cout<<j<<" ";
        cout<<endl;
        return 0;
    }
    pos[sum]=i;
}

    return 0;
}
