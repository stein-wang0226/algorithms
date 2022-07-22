#include <bits/stdc++.h>
#define LOCAL
#define int long long
// K 从左到右共cnt1-k+1   种统计左右的0个数相乘即可
//统计每个一左右连续0的个数
using namespace std;
const int N = 2e6 + 5;
int T, n, k;
int l[N], r[N];  // 左右0 的个数
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  string s, s1;
  cin >> k;
  cin >> s;
  int len = s.size();

  int cnt = 0;
  int cnt1 = 0;
  
  
  
  if(k==0){// 特判
  int ans=0;
  int cnt=0; // 连续0个数   +（cnt+1）*cnt/2
    for(int i=0;i<len;i++){
        if(s[i]=='0')cnt++;
        else{
            ans+=(cnt+1)*cnt/2;
            cnt=0;
        }
    }
    if(cnt){    // ***末尾0不要漏加
        ans+=(cnt+1)*cnt/2;
    }
        cout<<ans<<endl;
        return 0;
    }

  for (int i = 0; i < len; i++) {
    if (s[i] == '0')
      cnt++;
    else {
      l[++cnt1] = cnt;
      cnt = 0;
    }
  }
    
  if(k>cnt1){  //特判2
      cout<<0<<endl;
      return 0;
  }
    cnt=0;int cnt11=0;
  for (int i = len-1; i>=0; i--) {
    if (s[i] == '0')
      cnt++;
    else {
      r[cnt1+1-(++cnt11)] = cnt;
      cnt = 0;
    }
  }
int ans=0;
for(int i=1;i<=cnt1-k+1;i++){// 起始
int j=k-1+i;  // 右
ans+=(l[i]+1)*(r[j]+1);
}
cout<<ans<<endl;
  return 0;
}
