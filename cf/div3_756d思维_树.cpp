#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX = 2e5 + 5;
//阅读理解思维水题
int t,  n, p[MAX],fa[MAX],dist[MAX],sum[MAX];
int main() {//sum 为i到root距离   dist为边权
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n;
    int root;
    memset(fa,0,sizeof fa);
        memset(dist,0,sizeof dist);
            memset(sum,-1,sizeof sum);//-1标记为出现
    for (int i = 1; i <= n; i++) {cin >> fa[i];if(fa[i]==i)root=i;}
    for (int i = 1; i <= n; i++) cin >> p[i];
    if(p[1]!=root){cout<<"-1"<<endl;continue;}
    int dis=0;dist[root]=0;sum[root]=0;
    int flag=1;
for(int i=2;i<=n;i++){//sum按1递增
  if(sum[fa[p[i]]]==-1){flag=0;break;}//父亲还未出现**
  dist[p[i]]=(i-1)-sum[fa[p[i]]];
  sum[p[i]]=i-1;
  if(dist[p[i]]<1){
    flag=0;break;
  }
}
if(flag){
  for(int i=1;i<=n;i++)
  cout<<dist[i]<<" ";
cout<<endl;
}
else cout<<"-1"<<endl;

  }
  return 0;
}
