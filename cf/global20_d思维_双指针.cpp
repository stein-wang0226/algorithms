#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N],b[N];
// 发现对不同区间操作先后不影响结果
//考虑 从b到a  对相邻相同的数  a[i-1]  a[i]  可以将a[i-1]  放到前面任何地方
//考虑用双指针  i,j   如果 a[i]==b[j] 则向后  否则 
//用map记录前面不匹配的a[i]  如果不匹配若map中无记录则记录 a向后：i++ 继续匹配 
//否则如果有记录且满足 b[j]==b[j-1] 可以将b[j-1] 移到上一个a[i]位置 
//如果都移不了则NO（i到头  j不能消）
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=1;j<=n;j++)cin>>b[j];

map<int,int>cnt; //记录之前不匹配的a元素
int flag=1;
int i=1,j=1;
while(j<=n){
    if(i<=n&&a[i]==b[j])i++,j++;
    else{
        if(cnt[b[j]]&&b[j]==b[j-1]){//可以消
            cnt[b[j]]--;
            j++; //消相应的a
        }
        else if(i<=n)cnt[a[i]]++,i++; //
        else {//（i到头  j不能消）
            flag=0;
            break;
        }
    }
}

if(flag)cout<<"YES"<<endl;
else cout<<"NO"<<endl;


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
