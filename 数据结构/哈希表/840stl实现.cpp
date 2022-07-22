#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
unordered_set<int> Hash;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    int a;
    cin >> s >> a;
    if (s == "I") {
      Hash.insert(a);
    } else {
      int ans = Hash.count(a);
      if (ans)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}