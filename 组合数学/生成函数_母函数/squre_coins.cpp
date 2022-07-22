#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;

int a[305],b[305];
int n;

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

memset(a,0,sizeof a);
memset(b,0,sizeof b);
  for(int i=0;i<=300;i++)
  a[i]=1;

  for(int i=2;i<=17;i++){
    for(int j=0;j<=300;j++)
      for(int k=0;k+j<=300;k+=i*i)//可无限次
        b[j+k]+=a[j];//

  for(int j=0;j<=300;j++){
    a[j]=b[j];
    b[j]=0;
  }

}
while(cin>>n,n){
  cout<<a[n]<<endl;
}

    return 0;
}
