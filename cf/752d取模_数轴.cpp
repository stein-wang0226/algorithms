#include<bits/stdc++.h>
using namespace std;
 //d  画图真easy
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    if (x <= y) {
      cout << y - y % x / 2 << '\n';//画数轴   y/x
    }
    else {
      cout << x + y << '\n';//想到了
    }
  }
  return 0;
}
