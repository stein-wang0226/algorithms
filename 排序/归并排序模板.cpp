#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N],temp[N];

void merge_sort(int *a,int l,int r){
    if(l>=r)return ;
    int mid=l+r>>1;
    merge_sort(a,l,mid);merge_sort(a,mid+1,r);// 递归到单个

    int k=1,i=l,j=mid+1;//同时从开头比较
    while(i<=mid&&j<=r){//直到一方清空
    if(a[i]<=a[j])temp[k++]=a[i++];
    else temp[k++]=a[j++];
    }
    while(i<=mid)temp[k++]=a[i++];//可能一方还有剩余
    while(j<=r)temp[k++]=a[j++];

    for(int i=l,j=1;i<=r;i++,j++)a[i]=temp[j];// 重新赋值注意下标
    
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];

merge_sort(a,1,n);

for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    return 0;
}
