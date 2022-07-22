#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e6+5;
int T,n;
int c,cnt[N],a[N],sum[N];
// 枚举倍数 ：调和级数  不会T
//  枚举x的倍数 kx  则若[kx,(k+1)x-1]区间中有数存在 则数组中必然有k  否则寄
// 作每个数出现次数的前缀和
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif


cin>>T;
while(T--){
cin>>n>>c;
memset(cnt,0,sizeof cnt);
sum[0]=0;
for(int i=1;i<=n;i++){
    cin>>a[i];
    cnt[a[i]]++;
}
if(n==1){
    if(a[1]==1)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    continue;
}


for(int i=1;i<=c;i++){
    sum[i]=sum[i-1]+cnt[i];
}
int flag=1;

sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
    if(a[i]==1)continue;
    if(!flag)break;
    for(int k=1;k*a[i]<=c;k++){// 枚举倍数
    int l=k*a[i];
    int r=min((k+1)*a[i]-1,c);  //注意边界
        if(sum[r]-sum[l-1]>0){// k需要存在
            if(!cnt[k]){flag=0;break;}
        }
    }
}
if(flag)cout<<"yes"<<endl;
else cout<<"no"<<endl;


}
    return 0;
}
