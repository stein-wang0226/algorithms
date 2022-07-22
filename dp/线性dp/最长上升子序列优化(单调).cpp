#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 最大上升子序列优化 O nlogN
// 显然 长度位n的最长上升子序列  对应每种情况结尾最小值关于n单调递增 存于q[N] (反证法)
//每次维护每种情况答案的结尾最小值   每次用二分查找a[i] 于q[]  找到第一个大于等于于a[i] 的q中位置k  用ans=max(ans,k)  同时用a[i]更新q[k];  
using namespace std;
const int N=1e5+5;
int a[N],q[N],n;
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int ans=0;
for(int i=1;i<=n;i++){
  int l=0,r=ans;  // r从0开始
 while(l<r){//找到第一个小于a[i]  (大于可能找不到)
   int mid=l+r+1>>1;
   if(q[mid]<a[i])l=mid;
   else r=mid-1;
 }
  ans=max(ans,l+1);//  用l+1更新答案(第一个大于等于a{i}的位置)  
  q[l+1]=a[i];  //维护q[] 原本为0则相当于接上后达到新长度
}

cout<<ans<<endl;
    return 0;
}
