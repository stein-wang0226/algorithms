#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n;
vector<int> add(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) return add(B, A);

  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }

  if (t) C.push_back(t);
  return C;
}
vector<int> sub(vector<int> &A, vector<int> &B)  //减
{
  vector<int> C;
  for (int i = 0, t = 0; i < (int)A.size(); i++) {
    t = A[i] - t;
    if (i < (int)B.size()) t -= B[i];
    C.push_back((t + 10) % 10);
    if (t < 0)
      t = 1;
    else
      t = 0;
  }

  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

bool cmp(vector<int> &A, vector<int> &B) {
  if (A.size() != B.size()) return A.size() > B.size();

  for (int i = A.size() - 1; i >= 0; i--)
    if (A[i] != B[i]) return A[i] > B[i];

  return true;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  string s1, s2;
  vector<int> v1, v2;
  cin >> s1 >> s2;
  int flag1 = 1, flag2 = 1;
  string ss1 = s1;
  string ss2 = s2;
  if (s1[0] == '-') {
    flag1 = 0;
    ss1 = s1.substr(1);
  }
  if (s2[0] == '-') {
    flag2 = 0;
    ss2 = s2.substr(1);
  }

  reverse(ss1.begin(), ss1.end());
  reverse(ss2.begin(), ss2.end());
  for (auto i : ss1) {
    int k = i - '0';
    v1.push_back(k);
  }
  for (auto i : ss2) {
    int k = i - '0';
    v2.push_back(k);
  }
  vector<int> ans1, ans2;

  ans1 = add(v1, v2);  // 绝对值之和
  if (cmp(v1, v2))     // 绝对值之差
    ans2 = sub(v1, v2);
  else
    ans2 = sub(v2, v1);

  reverse(ans1.begin(), ans1.end());
  reverse(ans2.begin(), ans2.end());

  cout << s1 << '+' << s2 << "=";
  vector<int> res1, res2;

// 特判0 无符号


  if (flag1 && flag2) {  //全+
    for (auto i : ans1) {
      cout << i;
    }
  }
  else if(flag1^flag2){
      int flag3=cmp(v1,v2);
      if((flag3&&!flag1||!flag3&&flag1)&&ans2[0]!=0)cout<<"-";
    for (auto i : ans2) {
      cout << i;
    }
  }
  else {
      if(ans1[0]!=0)cout<<'-';
      for (auto i : ans1) {
      cout << i;
    }
  }

  cout << '\n';
  cout << s1 << '-' << s2 << "=";
  if (flag1 && !flag2) {  //  + - -
    for (auto i : ans1) {
      cout << i;
    }
  }
  else if(!flag1&&flag2) { //- - +
      if(ans1[0]!=0)cout<<'-';
      for (auto i : ans1) {
      cout << i;
    }
  }
    else {  //+ - +   - - -
      int flag3=cmp(v1,v2);
      if((!flag3&&flag1||flag3&&!flag1)&&(ans1[0]!=0))cout<<"-";
    for (auto i : ans2) {
      cout << i;
    }
  }
  cout << '\n';

  return 0;
}
