#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int N=2e5+5;
//利用双指针  记录第一个不配对的数处理 ，若有第二个则no
int T,n,m,a[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int l=1,r=n;
int cnt1,cnt2;
while(l<r){
  if(a[l]==a[r]){
    l++,
    r--;
  }
  else {
    cnt1=a[l];
    cnt2=a[r];
    break;
  }
}
int l1=l,l2=l,r1=r,r2=r;
int flag1=1,flag2=1;
while(l1<r1){//删cnt1
  while(a[l1]==cnt1)l1++;
  while(a[r1]==cnt1)r1--;
  if(l1>=r1)break;
  if(a[l1]==a[r1]){
    l1++;
    r1--;
  }
  else{
    flag1=0;
    break;
  }
}

while(l2<r2){//删cnt2
  while(a[l2]==cnt2)l2++;
  while(a[r2]==cnt2)r2--;
  if(l1>=r1)break;
  if(a[l2]==a[r2]){
    l2++;
    r2--;
  }
  else{
    flag2=0;
    break;
  }
}

if(flag1||flag2)cout<<"yes"<<endl;
else cout<<"no"<<endl;


}
    return 0;
}
