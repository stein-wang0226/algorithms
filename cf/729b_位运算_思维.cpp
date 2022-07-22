#include <bits/stdc++.h>
//#define LOCAL
//相邻异或最大值最小，考虑最大值，至少一个最高位为1的和为0的做异或，所以从大到小排列，
//将最高位的1000..后放0，这样保证最大值就是1000...(min)
using namespace std;
int t,n;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin >> n;
int k=1;
while(k<n)k*=2;
k/=2;
 for(int i = n - 1; i >= 1; i --) {
 cout << i << " ";
 if(i == k) cout << 0 << " ";
 }
 cout << endl;;
 
 
 
  
}
    return 0;
}