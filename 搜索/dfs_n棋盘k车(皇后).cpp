#include<bits/stdc++.h>
using namespace std;
//n*n棋盘 k车 dfs
int n,k;
char Map[105][105];
map<int,int>vis1;
int ans=0;
int check(int x,int y)
{
  if(Map[x][y]=='.')return 0;
  if(vis1[y]==1)   return 0;
  return 1;
}
int cnt;
int dfs(int x)
{
  if(cnt==k||x>n){
    if(cnt==k)ans++;
    return 0;
  }
  for(int j=1;j<=n;j++){
    if(check(x,j)){
      vis1[j]=1;
      cnt++;
      dfs(x+1);
      vis1[j]=0;
      cnt--;

    }
  }
  dfs(x+1);
}


int main()
{
  while(cin>>n>>k){
    if(n==-1&&k==-1)break;
    vis1.clear();
    cnt=0;
    ans=0;
    memset(Map,0,sizeof Map);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin>>Map[i][j];
      }
    }
    dfs(1);
    cout<<ans<<endl;
  }

}
















