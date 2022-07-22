#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//最小值的最大值  典型贪心+二分
const int MAX=2e5+5;
int n,t,a[MAX];
int inf=0x3f3f3f3f;

int check(int mid){//贪心
//check mid是否能为最小值：
//由于只有后面能移给前面  所以从后往前遍历一次,只要大于mid就把多余的向前移动每次判断当前是否大于mid;
vector<int> cur_a(a, a + n);//将a拷贝到cur_a  储存结果   vector新用法
for(int i=n-1;i>=2;i--){
  if(cur_a[i]<mid)return 0;//每次判断当前即可  因为之后操作不会改变
  int d = min(a[i], cur_a[i] - mid) / 3;//移动的d   (不能超过原来的1/3)
  cur_a[i]-=3*d;//可有可无 因为一次遍历结束判断
  cur_a[i-1]+=d;
  cur_a[i-2]+=2*d;
}
return (cur_a[1]>=mid&&cur_a[0]>=mid);//判断开头两个

}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
  cin>>n;
  int l=0;
  int r=0;
  for(int i=0;i<n;i++){//从零开始  因为要拷贝给vector
    cin>>a[i];
    if(a[i]>r)r=a[i];
  }


while(l<r){
int mid=(l+r+1)/2;
if(check(mid))l=mid;
else r=mid-1;
}
cout<<l<<endl;



}
    return 0;
}
