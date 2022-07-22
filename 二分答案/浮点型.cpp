#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
const double eps=1e-6;
const int N = 2e5 + 5;
int T, n, m;
double  a[N];
int check(double mid){
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=(int)floor(a[i]/mid);
    }
    return sum>=m;
}

void solve(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    double l=0,r=1e5;
    while(r-l>eps){
        double mid=(l+r)/2.0;
        if(check(mid))l=mid;
        else r=mid;
    }

printf("%.2lf\n",l);
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

while(cin>>n>>m,n+m){
    solve();
}
  return 0;
}
