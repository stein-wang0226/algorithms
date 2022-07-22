#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//考虑清楚k==n-1 的情况  n-1~n-2   n-3~1   0~2
int t, n, k;
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k == n - 1) {
      if (n == 4) {
        cout << "-1" << endl;
        continue;
      }
      else {
        cout<<n-1<<" "<<n-2<<endl;
        cout<<n-3<<" "<<"1"<<endl;
        cout<<"0"<<" "<<"2"<<endl;
        for(int i=3;i<n/2;i++){
          cout<<i<<" "<<n-i-1<<endl;
        }
      }
      continue;
    }
    cout << k << " " << n - 1 << endl;//k<n-1    k~n-1   0~n-k-1    其余相配

    for (int i = 1; i < n / 2; i++) {
      if (i == k) continue;
      if ((i + k + 1) != n) cout << i << " " << n - 1 - i << endl;
    }
    if (k != 0)
      cout << "0"
           << " " << n - 1 - k << endl;
  }
  return 0;
}
