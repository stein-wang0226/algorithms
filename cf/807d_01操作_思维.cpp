#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e3 + 5;
int T, n, a[N];
struct Edge{
    int s,e;
}edge1[N*2],edge2[N*2];
void solve(){
    //该操作的本质是将连续1左右边延长/缩短  但不能将两段1相连  故该操作不会改变连续1段的总数（判总数相同）
// 还要特判首尾位置是否相同  因为不能修改
//然后最小步数计算：按顺序两两匹配  ，计算 左右端点(可重合)需移动距离之和 即为答案 
cin>>n;
string s,ss;
cin>>s>>ss;


if(s[0]!=ss[0]||s[n-1]!=ss[n-1]){
    cout<<"-1"<<endl;
    return ;
}
int cnt1=0,cnt2=0;
int flag=0;
for(int i=0;i<n;i++){
    if(s[i]=='1'){
        if(!flag){//起点
            flag=1;
            edge1[++cnt1].s=i;
        }
        if(flag&&(i<n-1&&s[i+1]=='0'||i==n-1)){//终点
            edge1[cnt1].e=i;
        }
    }
    else flag=0;
}
flag=0;
for(int i=0;i<n;i++){
    if(ss[i]=='1'){
        if(!flag){
            flag=1;
            edge2[++cnt2].s=i;
        }
    if(flag&&(i<n-1&&ss[i+1]=='0'||i==n-1)){//终点            
            edge2[cnt2].e=i;
        }
    }
    else flag=0;
}


if(cnt1!=cnt2){
    cout<<-1<<endl;
    return;
}
int ans=0;
for(int i=1;i<=cnt1;i++){
    ans+=abs(edge1[i].s-edge2[i].s);
    ans+=abs(edge1[i].e-edge2[i].e);
}
cout<<ans<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}
