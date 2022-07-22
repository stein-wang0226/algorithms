#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n, a[N];
int c,q,k;
int l[N],r[N]; 
int sum[N]; //前i段总长度
void solve(){
    string s;
//  从后往前递推
cin>>n>>c>>q;
cin>>s;
sum[1]=n;

for(int i=2;i<=c+1;i++){
    cin>>l[i]>>r[i];
    sum[i]=sum[i-1]+r[i]-l[i]+1;
}
for(int i=1;i<=q;i++){
    cin>>k;
    //
    for(int j=c+1;j>=2;j--){  //从后向前递推 推到第一段
        if(k>sum[j-1]&&k<=sum[j]){
            k=k-sum[j-1]+l[j]-1;   // 前推1次
        }
    }

    cout<<s[k-1]<<endl;
}


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
