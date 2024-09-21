#include <iostream>
#include <cstring>
using namespace std;
// 首先想到二分 如何check
// 对于已知跳跃长度y  容易发现对于任意一个长度为y的区间和都必须>2x （因为任意一段y区间一趟至少走一次），故为必要条件，
//同时也是充分条件因为如果所有长度为y的区间都能至少踩2x次，那么肯定能够完成2x次来回。

const int N=1e5+5;
int n,x,y;
int h[N],sum[N];


int check(int y){
  for(int i=1;i<=n-y;i++){
  if(sum[i+y-1]-sum[i-1]<2*x)return 0; // 
}
return 1;

}

int main()
{
  cin>>n>>x;
  memset(sum,0,sizeof sum);
  for(int i=1;i<=n-1;i++)cin>>h[i],sum[i]=sum[i-1]+h[i];
//二分

    int l=1,r=n;

  while(l<r){
    int mid =(l+r)/2;
    if(check(mid))r=mid;
    else l=mid+1;
  }
  cout<<l<<endl;


  return 0;
}