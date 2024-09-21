#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int  n;
// 与字串分值类似  挨个字符统计对总数的贡献
//记录a-z每个字符 的出现位置  统计贡献(总字串数-不含该字符的字串数)
// 字串总数 = (n+1)n/2  故对于相邻字符出现位置 i j 位置间不含该字符的字串数为 = (j-i)*(j-i-1)/2

map<char,vector<int>>pos; // 每个字符出现的各个位置

void solve(){
  string s;
  cin>>s;
  n= (int)s.size();
  int subnum= (n+1)*n/2;

  for(int i=0;i<n;i++){
    pos[s[i]].push_back(i+1);//
  }
  int ans =0 ;

for(auto it :pos){//26

    ans+=(n+1)*n/2;//先加上全部
    auto ch = it.first;
    auto poses = it.second;
    //方便处理
    poses.insert(poses.begin(),0);
    poses.push_back(n+1);
    int len = poses.size();
    for(int i=0;i<len-1;i++){
      int p1=poses[i],p2= poses[i+1];
      ans-=(p2-p1)*(p2-p1-1)/2;
    }
  }
  cout<<ans<<endl;

}
signed main() {

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  solve();

  return 0;
}
