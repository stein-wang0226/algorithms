#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n,m,k, a[N];
void solve(){
    //全部整行或整列 小的优先
cin>>n>>m>>k;
int sum=n*m;
for(int i=1;i<=k;i++){
    cin>>a[i];
}
sort(a+1,a+k+1,greater<int>());
 int minn = 0, maxx = 0;
    for(int i = 1; i <= k; i ++) {
        int tmp = a[i] / n;
        if(tmp >= 2) minn += 2, maxx+= tmp;
    if(m >= minn && m <= maxx) {cout<<"YES"<<endl; return;}
    }
    minn = 0, maxx = 0;
    for(int i = 1; i <= k; i ++) {
         int tmp = a[i] / m;
        if(tmp >= 2) minn += 2, maxx+= tmp;
    if(n <= maxx && n >= minn) {cout<<"yes"<<endl; return;}
    }
    cout<<"NO"<<endl;
    return;
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
// #include <bitsdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// void solve() {
//     int n, m, k;
//     scanf("%d%d%d", &n, &m, &k);
//     vector<int> a(k);
//     for(int i = 0; i < k; i ++)
//         scanf("%d", &a[i]);
//     sort(a.begin(), a.end());
//     reverse(a.begin(), a.end());
//     vector<int> b(k);
//     int l = 0, r = 0;
//     for(int i = 0; i < k; i ++) {
//         int t = a[i] / n;
//         if(t >= 2) l += 2, r += t;
//     if(m >= l && m <= r) {printf("Yes\n"); return;}
//     }
//     l = 0, r = 0;
//     for(int i = 0; i < k; i ++) {
//         int t = a[i] / m;
//         if(t >= 2) l += 2, r += t;
//     if(n <= r && n >= l) {printf("Yes\n"); return;}
//     }
//     printf("No\n");
// }


