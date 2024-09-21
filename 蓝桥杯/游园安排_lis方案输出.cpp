#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;
int T, n;
// LIS 最长上升子序列 二分贪心法
// 输出方案：利用pre[](记录子序列中的前一个位置元素)->记录路径 倒序输出即可 理由： pre 记录了交换/插入时该元素的上一个位置，
vector<string> names;
string dp[N];
map<int,int>pre;//记录上一个位置 ,用string映射可能会出现重复
void solve() {
  string s;
  cin >> s;
  string ss = "";
  for (auto ch: s) {
    if (ch >= 'A' && ch <= 'Z') {
      if (ss != "") {
        names.push_back(ss);
        ss = "";
      }
    }
    ss += ch;
  }
  names.push_back(ss);
  n = names.size();
    int len=0 ; //最大长度
    dp[0]="";
    vector<int>poses(n,-1); // 记录lis中每个位置当前元素在names中位置
    for(int i=0;i<n;i++){//维护单增
      if(names[i]>dp[len]) {
        pre[i] = poses[len];
        dp[++len] = names[i];
        poses[len] = i;
        }//大于末位直接接上 此时出现更优方案
        else{
            auto pos = lower_bound(dp+1,dp+1+len,names[i])-dp; //
            pre[i]=poses[pos-1];
            poses[pos] = i ;//更新
            dp[pos]=names[i]; //更新 将更小的替换进去 保证不漏最优
          }
        }
    //cout<<len;
        string ans;
        vector<string>tmp;
    int st = poses[len];//
    while(st!=-1){
      tmp.push_back(names[st]);
      st = pre[st];
    }
    reverse(tmp.begin(),tmp.end());
    for(auto ss:tmp)ans+=ss;
      cout<<ans<<endl;





  };

  signed main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    T = 1;
    while (T--) {
      solve();
    }
    return 0;
  }
