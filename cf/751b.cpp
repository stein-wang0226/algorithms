#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=2e3+5;
int T,n;
int a[N];
int ans[N][N];
int num[N];// 这一步第i个数出现次数
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
cin>>n;
for(int i=1;i<=n;i++){
  cin>> ans[0][i];
}
int step=1;
for(int i=1;i<=n;i++){   // 循环n次 结论 ：最多n轮就不会变化
memset(num,0,sizeof num);
  for(int j=1;j<=n;j++){
    num[ans[i-1][j]]++;
  }
  for(int j=1;j<=n;j++)ans[i][j]=num[ans[i-1][j]];
}
int q;
cin>>q;
while(q--){
  int x,k;
  cin>>x>>k;
  if(k>n)k=n;  // 最多n次变化
  cout<<ans[k][x]<<endl;
}

}
    return 0;
}
