#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
//开放寻址法   （蹲坑法）
//坑有人就向后找
const int N=200003;//开2（100000个数）倍 ，能较快找到坑 保证放得下
const int null=0x3f3f3f3f;//大于数据范围   可用于标识
int h[N];//  所有坑

int find(int x){//同时辅助实现插入  查找
  int k=(x%N+N)%N;
  while(h[k]!=null&&h[k]!=x){//已被占
    k++;
    if(k==N)k=0;//找到最后也没有
  }
  return k;//布尔值
}


signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int n;
cin>>n;
memset(h,0x3f,sizeof h);//   初始化为Null表示未占用
while(n--){
string s;int x;
cin>>s>>x;
if(s=="I"){
  h[find(x)]=x;//找到并 占据
}
else {
  if(h[find(x)]==null)puts("No");//无人占领
  else puts("Yes");
}



}
    return 0;
}
