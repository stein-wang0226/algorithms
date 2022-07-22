#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX=15e4+5;
int vis[MAX];//标记改数是否处理过
//问题为找两个相同数字的最短距离
vector<int>pos[MAX];//利用vector 减空间 换时间
int t,n,a[MAX];
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
    cin>>n;
    set<int>st;
for(int i=0;i<MAX;i++)pos[i].clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
        pos[a[i]].push_back(i);
    } 
int ans=0x3f3f3f3f;
for(auto i:st ){
  for(int j=0;j<pos[i].size()-1;j++){
      ans=min(ans,pos[i][j+1]-pos[i][j]);
  }
  if(ans==1)break;
}
if(ans==0x3f3f3f3f){
    cout<<"-1"<<endl;
    continue;
}
else cout<<n-ans<<endl;
}
    return 0;
}
