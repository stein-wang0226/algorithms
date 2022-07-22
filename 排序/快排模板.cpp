#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e5+5;
int a[N];
void quick_sort(int a[],int l,int r){
  if(l>=r)return ;
  int i=l-1,j=r+1,x=a[l+r>>1];//分界点
  while(i<j){
    do i++;while(a[i]<x);//一直移动到需要改变 
    do j--;while (a[j]>x);
    if(i<j) swap(a[i],a[j]);
  }
  quick_sort(a,l,j);
  quick_sort(a,j+1,r);
}

signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
cin>>n;
for(int i=0;i<n;i++){
  cin>>a[i];
}
quick_sort(a,0,n-1);
for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
