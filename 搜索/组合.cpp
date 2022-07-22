#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;

map<int,string>name;
vector<int>vec;

vector<int>ans[N];
int T, n, a[N],k;
int tot;
int vis[N];
void dfs(int cnt,int pos){
  if(k==cnt){
    tot++;
    for(auto i:vec){
      ans[tot].push_back(i);
    }
    cout<<endl;
    return;
  }
  for(int i=pos+1;i<=n;i++){
    if(!vis[i]){vec.push_back(i);
    vis[i]=1;
    dfs(cnt+1,i);
    vec.pop_back();
    vis[i]=0;}
  }

}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

cin>>n;
string s;
for(int i=1;i<=n;i++){
  cin>>s;
  name[i]=s;
}
cin>>k;
if(k>n){cout<< -1;return 0;}
vec.clear();
tot=0;
memset(vis,0,sizeof vis);

dfs(0,0);
cout<<tot<<endl;
for(int i=1;i<=tot;i++){
  for(auto j:ans[i]){
    cout<<name[j]<<" ";
  }
    cout<<endl;
}

  return 0;
}
