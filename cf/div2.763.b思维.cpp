#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//思路 每个区间从小到大排序  遍历，每次输出区间两端和未标记的一个点，再将其标记
int t,n,vis[1005];
struct edge{
  int a,b,len,val;
  bool operator<(const edge &b){
    return len<b.len;
  }
}e[1005];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>e[i].a>>e[i].b;
    e[i].len=e[i].b-e[i].a;
  }
  sort(e+1,e+1+n);
  memset(vis,0,sizeof vis);
  for(int i=1;i<=n;i++){
    for(int j=e[i].a;j<=e[i].b;j++){
      if(!vis[j]){
          cout<<e[i].a<<" "<<e[i].b<<" "<<j<<endl;;
        vis[j]=1;
        break;
      }
    }
  }
  cout<<endl;
}
    return 0;
}
