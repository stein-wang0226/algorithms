#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
const int MAX = 20005;
int cnt[105],w[105],t[105];
int a[MAX],b[MAX];
int n,sum;

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n){
  sum=0;
  
  memset(cnt,0,sizeof cnt);
  memset(w,0,sizeof w);
  memset(a,0,sizeof a);
  memset(b,0,sizeof b);
  for(int i=1;i<=n;i++){
      cin>>t[i];
      cnt[t[i]]++;
      sum+=t[i];
  }
  int count=0;
for(int i=1;i<=100;i++){
  if(cnt[i]>0){
    count++;
    w[count]=i;
  }
}
  for(int i=0;i<=cnt[w[1]]*w[1];i+=w[1])
  a[i]=1;

  for(int i=2;i<=count;i++){
      for(int j=0;j<=sum;j++)
        for(int k=0;k+j<=sum&&k<=w[i]*cnt[w[i]];k+=w[i])
         {
         b[j+k]+=a[j];//
          b[abs(j-k)]+=a[j];//天平可以相减
         }
    for(int j=0;j<=sum;j++){
      a[j]=b[j];
      b[j]=0;
    }
  }
int anscnt=0,ans[MAX];
memset(ans,0,sizeof ans);
  for(int i=1;i<=sum;i++){
    if(a[i]==0){
      anscnt++;
      ans[anscnt]=i;
    }
  }

  cout<<anscnt<<endl;
 if(anscnt){ for(int i=1;i<=anscnt;i++){
    cout<<ans[i];
    if(i!=anscnt)cout<<" ";
  }
  cout<<endl;
 }
}

    return 0;
}
