#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
int k[27],a[55],b[55];
int t;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
for(int i=1;i<=26;i++)
  cin>>k[i];
memset(a,0,sizeof a);
memset(b,0,sizeof b);
for(int i=0;i<=k[1];i++)
a[i]=1;
for(int i=2;i<=26;i++){
  for(int j=0;j<=50;j++){
      for(int l=0;l<=k[i]*i&&(j+l<=50);l+=i)
        b[j+l]+=a[j];
  }
  for(int j=0;j<=50;j++){//变量不要用i出错
    a[j]=b[j];
    b[j]=0;
  }
}
int cnt=0;
for(int i=1;i<=50;i++)//从1开始
cnt+=a[i];
cout<<cnt<<endl;
}
    return 0;
}
