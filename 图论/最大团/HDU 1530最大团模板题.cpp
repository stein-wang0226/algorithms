#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
// 最大团模板题


const int N = 2e3 + 5;
int Map[N][N];
int U[N];  // 集合U中的点
int T, n, a[N],ans;

bool is_clique(int num,int node){  // 判断带你node是否与U中每个点相连
  for(int i=1;i<=num;i++){
    if(!Map[U[i]][node])return false; // 存在不相连的 不能构成完全子图 
  }
  return true;
}

void dfs(int depth,int cur){  // depth  递归深度 即当前团的大小   cur 当前元素  （从小到大向后搜）（无向图）
  if(n-cur+depth+1<=ans)return;  // 就算后后面元素都加上也不可能更大
  for(int i=cur;i<=n;i++){
      if(is_clique(depth,i)){
        U[depth+1]=i;
        dfs(depth+1,i+1);
      }
  }
  ans=max(ans,depth);


}
    
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (cin>>n,n) {
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin>>Map[i][j]; // 读入临界矩阵
      }
    }
    ans=0;
    dfs(0,1);
    cout<<ans<<endl;

  }
  return 0;
}
